#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////
const ll inf = 1LL<<60;

bool isprime[100010];
int a[100010];

void sieve(int n)
{
  for (int i=0; i<=n; i++) isprime[i] = true;
  isprime[0] = isprime[1] = false;
  for (int i=2; i<n; i++) {
    if (isprime[i]) {
      for (int j=2*i; j<=n; j+=i) isprime[j] = false;
    }
  }
}

int main()
{
  int q; cin>>q;
  vector<int> ans;

  sieve(100000);
  for (int i=1; i<=100000; i++) {
    if (i%2 && isprime[i] && isprime[(i+1)/2]) a[i]++;
    a[i+1] += a[i];
  }

  while (q--) {
    int l,r; cin>>l>>r;
    cout << a[r]-a[l-1] << endl;
  }

  return 0;
}

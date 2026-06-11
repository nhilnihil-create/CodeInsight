#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> a(N);
  REP(i, N) cin >> a[i];

  sort(ALL(a));
  vector<pair<int,int>> b;
  map<int,int> c;
  REP(i,N){
    c[a.at(i)]++;
  }

  for(auto x:c){
    b.push_back(make_pair(x.second,x.first));
  }
  sort(ALL(b));
  reverse(ALL(b));

  int sum = 0;
  int d = min(K,int(b.size()));
  REP(i,d){
    sum+=b.at(i).first;
  }

  cout << N - sum << endl;
}
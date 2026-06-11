#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int a,b,k;
  cin>>a>>b>>k;
  vector<int> v;
  for(int i = 1; i <= min(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      v.push_back(i);
    }
  }
  sort(v.begin(), v.end(), greater<int>());
  cout << v[k - 1];
}

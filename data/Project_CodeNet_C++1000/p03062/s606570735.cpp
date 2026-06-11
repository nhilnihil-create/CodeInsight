#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int minus=0;
  rep(i,n) {
    int x;
    cin >> x;
    if(x<0) {
      minus++;  x=-x;
    }
    a[i]=x;
  }
  sort(rng(a));
  ll sum=0;
  rep(i,n) sum+=a[i];
  if(minus%2==1) sum-=2*a[0];
  cout << sum << endl;
  return 0;
}
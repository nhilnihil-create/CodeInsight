#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define YESNO(i) puts((i)?"YES":"NO");
#define YesNo(i) puts((i)?"Yes":"No");
#define yesno(i) puts((i)?"yes":"no");
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k;cin>>k;
  print(k/2*(k+k%2)/2);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
ll a[100200]={};
int main(void){
  ll n,q;
  string s;
  cin>>n>>q>>s;
  for(int i=1;i<n;i++){
    a[i]=a[i-1];
    if(s[i-1]=='A'&&s[i]=='C') a[i]++;
  }
  for(int i=0;i<q;i++){
    ll L,R;
    cin>>L>>R;
    L--,R--;
    if(L==0) cout<<a[R]<<endl;
    else{
      cout<<a[R]-a[L]<<endl;
    }
  }
}
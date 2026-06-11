#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  ll n,sum1=0,sum2=0;
  cin >> n;
  vector<vector<ll>> v(n,vector<ll>(3,0));
  vector<ll> v2(n);
  r(i,n)cin >> v[i][1];
  r(i,n){
    cin >> v[i][2];
    v[i][0]=v[i][1]-v[i][2];
    sum1+=v[i][1]; sum2+=v[i][2];
  }
  if(sum1<sum2)cout<<-1<<endl;//絶対むり
  else{
  sort(v.begin(),v.end());
    r(i,n)v2[i]=v[i][0];
  ll i=0,j=n-1;
  while(v[i][0]<0){
    if(v[j][0]+v[i][0]<0){
      v[i][0]+=v[j][0];
      v[j][0]=0;
    }
      else {
        v[j][0]+=v[i][0];
        v[i][0]=0;
      }     
    if(v[j][0]==0)j--;
    if(v[i][0]>=0)i++;
  }
    ll ans=0;
    r(i,n)if(v[i][0]!=v2[i])ans++;
    cout<<ans<<endl;
  }
}
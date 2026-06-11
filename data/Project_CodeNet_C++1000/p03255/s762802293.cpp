#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i++<n;)
ll INF=1e+18;

int main(){
  ll n,X,x[200010],rw[200010]={},temp,ans=INF,p;
  cin>>n>>X;
  fr(i,n) cin>>x[i];
  fr(i,n) rw[i]=rw[i-1]+x[i];
  fr(i,n){
    p=n-2*i;
    temp=(n+i)*X+5*rw[n];
    while(p>0){
      temp+=2*rw[p];
      p-=i;
      if(temp<0){
        temp=INF;
        break;
      }
    }
    ans=min(ans,temp);
  }
  cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll n,h,w,a,b,ans=0;
  cin>>n>>h>>w;
  fr(i,n){
    cin>>a>>b;
    if(a>=h&&b>=w) ans++;
  }
  cout<<ans<<endl;
}
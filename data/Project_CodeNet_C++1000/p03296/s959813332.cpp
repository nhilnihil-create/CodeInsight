#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef pair<ll,ll> pll;
vector<ll> A;
int main(){
 ll n,ans=0,x,temp=-1,sum=1;
 cin>>n;
 rep(i,n){
     cin>>x;
     if(temp==x)
     {
         sum+=1;
     }
     else if(i!=0){
         ans+=sum/2;
         sum=1;
     }
     temp=x;
 }
 if(sum>1)ans+=sum/2;
 cout<<ans<<endl;
}
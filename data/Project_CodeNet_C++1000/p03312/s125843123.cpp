#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
  	ll A[200000],p,q,r,s=0,i,j,k,ans=1e15;
    forn(i,n) cin>>A[i];
    p=A[0],q=0,r=A[1]+A[2],j=0,k=2;
    forn(i,n-3) s+=A[i+3];
    for(i=1;i<n-2;i++){
        q+=A[i],r-=A[i];
        while(abs(p-q)>abs(p-q+2*A[j+1])) p+=A[j+1],q-=A[j+1],j++;
        while(abs(r-s)>abs(r-s+2*A[k+1])) r+=A[k+1],s-=A[k+1],k++;
        ans=min(ans,max({p,q,r,s})-min({p,q,r,s}));
    }
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n;cin>>n;
    ll a[200010];
    rep(i,0,n)cin>>a[i];
    ll ng=0,an=a[n-1];
    if(a[0]!=0)ng=1;
    rep(i,0,n-1){
        if(a[i]<a[i+1]&&a[i+1]-a[i]!=1)ng=1;
        if(a[i]>=a[i+1])an+=a[i];
    }
    if(ng)cout<<-1<<endl;
    else cout<<an<<endl;
}
    








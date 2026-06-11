#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    ll n,y;
    cin>>n>>y;
    vector<ll> a(3,-1);
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n&&j+i<=n;j++){
            ll k=n-(i+j);
            if(i*10000LL+j*5000LL+k*1000LL==y){
                a[0]=i;
                a[1]=j;
                a[2]=k;
            }
        }
    }
    for(int i=0;i<3;i++) cout<<a[i]<<' ';
    cout<<endl;
}
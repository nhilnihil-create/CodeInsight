#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll n;
vector<ll> t(100100),x(100100),y(100100);

int main(){
    cin>>n;
    rep(i,0,n) cin>>t[i]>>x[i]>>y[i];

    bool flag=true;
    rep(i,0,n){
        if(t[i]<x[i]+y[i]){
            flag=false;
            break;
        }
        if(x[i]==0 && y[i]==0){
            if(t[i]%2!=0){
                flag=false;
                break;
            }
        }
        else if(t[i]%2!=(x[i]+y[i])%2){
            flag=false;
            break;
        }
        if(i>0){
            if(t[i]-t[i-1]<abs(x[i]-x[i-1])+abs(y[i]-y[i-1])){
                flag=false;
                break;
            }
        }
    }
    if(flag) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}
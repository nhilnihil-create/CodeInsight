#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,H,index;
    cin>>N;
    ll x[N],y[N],h[N];
    for(ll i=0;i<N;i++){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i]) index=i;
    }
    for(ll i=0;i<=100;i++){
        for(ll j=0;j<=100;j++){
            ll cnt=0;
            bool f=true;
            H=abs(j-x[index])+abs(i-y[index])+h[index];
            for(ll k=0;k<N;k++){
                if(h[k]>0&&H!=abs(j-x[k])+abs(i-y[k])+h[k]) f=false;
                if(h[k]==0&&H>abs(j-x[k])+abs(i-y[k])) f=false;
            }
            if(f){
                cout<<j<<" "<<i<<" "<<H<<endl;
                return 0;
            }
        }
    }
}
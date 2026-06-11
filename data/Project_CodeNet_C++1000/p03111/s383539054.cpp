#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;
ll A,B,C;

ll F(ll a,ll b, ll c){
    if(a==0||b==0||c==0)return INF;
    return abs(a-A)+abs(b-B)+abs(c-C);
}

int main(){
    ll N;
    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;
    vector<ll> l(N+1,0);
    for(ll i=0;i<N;i++){
        cin>>l[i+1]
    ;}
    ll ans=INF;
    for(ll bits=0;bits<(1<<(2*N));bits++){
        ll a=0,b=0,c=0;
        ll cost=0;
        for(ll j=1;j<=N;j++){
            bool s=0,t=0;
            if(bits&(1<<(2*j-2)))s=1;
            if(bits&(1<<(2*j-1)))t=1;
            if(s&&t){if(a>0)cost+=10;a+=l[j];}
            if(s&&(!t)){if(b>0)cost+=10;b+=l[j];}
            if((!s)&&t){if(c>0)cost+=10;c+=l[j];}
        ;}
        cost+=F(a,b,c);
        ans=min(ans,cost);
    ;}
    cout<<ans<<endl;

    return 0;
}

#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    ll ans =  0;
    int n;
    ll h;
    cin>>n>>h;
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector<ll> spe;
    if(v[0].second>=h){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        spe.push_back(v[i].second);
    }
    sort(spe.begin(),spe.end());
    reverse(spe.begin(),spe.end());
    for(int i=0;i<spe.size();i++){
        if(v[0].second>=h){
        cout<<ans+1<<endl;
        return 0;
        }
        if(spe[i]>=v[0].first){
            ans++;
            h-=spe[i];
        }
        if(h<=0){
            cout<<ans<<endl;
        }
    }
    while(1){
        if(h-v[0].second<=0){
            cout<<ans+1<<endl;
            return 0;
        }
        h-=v[0].first;
        ans++;
        if(h<=0){
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}
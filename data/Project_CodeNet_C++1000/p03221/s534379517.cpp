#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

string num(ll a,ll b){
    string x="";
    string y=x;
    while(a){
        x.pb('0'+a%10);
        a/=10;
    }
    while(sz(x)<6){x.pb('0');}
    reverse(x.begin(),x.end());
    while(b){
        y.pb('0'+b%10);
        b/=10;
    }
    while(sz(y)<6){y.pb('0');}
    reverse(y.begin(),y.end());
    return x+y;
}

int main() {
    int N,M;
    cin>>N>>M;
    vector<map<ll,int>> city(N+1);
    rep(i,M){
        int p;ll y;
        cin>>p>>y;
        city[p][y]=i;
    }
    vector<string> ans(M);
    rep(i,N+1){
        if(city.at(i).size()==0)continue;
        int cnt=0;
        for(LP C:city.at(i)){
            cnt++;
            ans.at(C.second)=num(i,cnt);
        }
    }
    rep(i,M){
        cout<<ans.at(i)<<endl;
    }
}
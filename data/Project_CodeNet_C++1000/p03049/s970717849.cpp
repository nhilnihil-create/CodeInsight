#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    ll ans=0;
    ll coua=0;
    ll coub=0;
    ll ex=0;
    for(ll i=0;i<N;i++)cin>>S[i];
    for(ll i=0;i<N;i++){
        ll n=S[i].size();
        for(ll j=1;j<n;j++){
            if(S[i][j-1]=='A'&&S[i][j]=='B')ans++;
        }
        if(S[i][0]=='B'&&S[i][n-1]!='A')coub++;
        else if(S[i][n-1]=='A'&&S[i][0]!='B')coua++;
        else if(S[i][0]=='B'&&S[i][n-1]=='A')ex++;
    }
    ll coua2=coua,coub2=coub;
    if(N==1){print(ans) return 0;}
    if(ex==0){
        print(ans+min(coua,coub))
        return 0;
    }
    ans+=ex-1;
    if(coua2&&coub2){
        coua2--;ans++;coub2--;ans++;ans+=min(coua2,coub2);
    }
    else if(coua2==0&&coub2){
        ans++;
    }
    else if(coub2==0&&coua2){
        ans++;
    }

    print(ans)


    return 0;
}

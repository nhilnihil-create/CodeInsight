#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

int main(){
    ll N, M; cin >> N >> M;
    vll A(N);
    rep(i, 0, N){
        cin >> A[i];
    }   
    vll cumod(N+1);
    ll cum = 0;
    cumod[0] = 0;
    rep(i, 0, N){
        cum += A[i] % M;
        cum %= M;
        cumod[i+1] = cum; 
    }
    Map mp;
    set<ll> st;
    rep(i, 0, N+1){
        ll t = cumod[i];
        st.insert(t);
        if(mp.find(t) == mp.end()){
            mp[t] = 1;
        }else{
            mp[t]++;
        }
    }
    ll ans = 0;
    for(auto x: st){
        if(mp[x] > 1){
            ans += (mp[x]*(mp[x]-1)/2);
        }
    }
    prt(ans);
}
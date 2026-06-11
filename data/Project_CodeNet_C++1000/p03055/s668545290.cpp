#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vvll nei(n);
    REP(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        nei[a].pb(b);
        nei[b].pb(a);
    }
    if(n==1){
        cout << "First" << endl;
        return 0;
    }else if(n==2){
        return 0;
    }
    vll dep(n);
    dep[0]=0;
    stack<ll> st;
    st.push(0);
    vll par(n);
    par[0]=-1;
    ll v = 0;
    while(!st.empty()){
        ll now = st.top();
        st.pop();
        for(ll i:nei[now]){
            if(i!=par[now]){
                dep[i]=dep[now]+1;
                par[i] = now;
                st.push(i);
                if(dep[i]>dep[v]) v = i;
            }
        }
    }
    dep = vll(n,0);
    dep[v]=0;
    st.push(v);
    par = vll(n,0);
    par[0]=-1;
    ll u = v;
    while(!st.empty()){
        ll now = st.top();
        st.pop();
        for(ll i:nei[now]){
            if(i!=par[now]){
                dep[i]=dep[now]+1;
                par[i] = now;
                st.push(i);
                if(dep[i]>dep[u]) u = i;
            }
        }
    }
    ll l = dep[u];
    if(l%3==1){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define X ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(2)<<(x)
 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
// long long p = 1e9+7;
 
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<int> VI;
typedef vector<pair<ll,ll>> VP;
typedef vector<ll> VL;
typedef vector<bool> VB;
 
// typedef pair<ll, ll> PL;
typedef unordered_map<ll, ll> UMP;
#define FOR(i,b) for(i=0;i<b;i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
 
// typedef  unordered_set<ll>;
 
 
void printa(VI &x,ll n){
    ll i;
    FOR(i, n){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
 
 
/////GLOABLS VARS
ll MOD = 1e9+7;
ll gmx = 1e6+7; 

VL fact(gmx, 1);
//////FUNCTIONS
ll powp(ll val, ll deg)
{
    // debug(val, deg);
    if (!deg)
        return 1;
    if (deg & 1)
        return (powp(val, deg - 1) * val) % MOD;
    ll res = powp(val, deg >> 1);
    // debug(res);
    return (res * res) % MOD;
}





//It is not easy but it can be fun, if you think!!!

//
// ll mx = 200+7;
// ll mx = 1e6+7;
// vector<VL> adj(mx+1);
// VL arr(mx);
// VL seg(4*mx);
// VL update(4*mx);
// // VL arr(mx);
// ll n,k,l,i,j,m;
// bool dfs(ll pos, bool tide, ll tide_pos){
//     debug(pos,tide,tide_pos);
//     ll new_tide;
//     // if(arr[i])
//     if(pos==n+2){
//         return true;
//     }
//     if(tide_pos+arr[pos]>l){
//         return false;
//     }
//     if(tide){
//         new_tide = tide_pos+1;
//     }
//     else{
//         new_tide = tide_pos-1;
//     }
//     if(new_tide>k){
//         new_tide--;
//         tide = !tide;
//     }


//     if(dfs(pos+1, tide, new_tide)){
//         return true;
//     }
//     if(dfs(pos, tide, new_tide)){
//         return true;
//     }
//     return false;

// }

ll mx = 1e6+7;
vector<VL> adj(mx+1);
VL arr(mx);
VL seg(4*mx);
VL update(4*mx);

void createSegTree(ll lf, ll rt, ll pos){
    if(lf==rt){
        seg[pos] = arr[lf];
        return;
    }
    ll mid = lf+(rt-lf)/2;
    createSegTree(lf, mid, 2*pos+1);
    createSegTree(mid+1, rt, 2*pos+2);
    seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
    return;
};

ll querySegTree(ll lf, ll rt, ll cur_lf, ll cur_rt, ll pos){
    if(update[pos]!=0){
        seg[pos]+=update[pos];
        if(cur_lf!=cur_rt){
            update[2*pos+1]+=update[pos];
            update[2*pos+2]+=update[pos];
        }
        update[pos] = 0;
    }
    if(lf<=cur_lf && rt>=cur_rt){
        return seg[pos];
    }
    else if(cur_lf>rt || lf>cur_rt){
        return 1e18;
    }
    else{
        ll mid = cur_lf+(cur_rt-cur_lf)/2;
        return min(querySegTree(lf,rt, cur_lf, mid, 2*pos+1),querySegTree(lf,rt, mid+1, cur_rt, 2*pos+2));
    }
} 
void rangeUpdate(ll lf, ll rt, ll cur_lf, ll cur_rt, ll val, ll pos){
    // debug(cur_rt, cur_lf,lf,rt,val);
    if(update[pos]!=0){
        seg[pos]+=update[pos];
        if(cur_lf!=cur_rt){
            update[2*pos+1]+=update[pos];
            update[2*pos+2]+=update[pos];
        }
        update[pos] = 0;
    }
    if(lf<=cur_lf && rt>=cur_rt){
        seg[pos]+=val;
        if(cur_lf!=cur_rt){
            update[2*pos+1]+=val;
            update[2*pos+2]+=val;
        }
        return;
    }
    else if(cur_lf>rt || lf>cur_rt){
        return;
    }
    else{
        ll mid = cur_lf+(cur_rt-cur_lf)/2;
        rangeUpdate(lf,rt, cur_lf, mid, val,2*pos+1);
        rangeUpdate(lf,rt, mid+1, cur_rt, val, 2*pos+2);
        if(cur_lf!=cur_rt){
            seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
        }
    }
}

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    // #endif
    ll n,i,j,k;
    cin>>n;
    vector<vector<pl>>adj(n+1);
    FOR(i,n-1){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    queue<ll> st;
    st.push(1);
    VL col(n+1,-1);
    col[1]=0;
    while(st.size()>0){
        ll el = st.front(); st.pop();
        for(auto nb:adj[el]){
            if(col[nb.fi]!=-1){continue;}
            if(nb.se&1){col[nb.fi]=1-col[el];}
            else{
                col[nb.fi] = col[el];
            }
            st.push(nb.fi);
        }
    }
    for(i=1;i<=n;i++){
        cout<<col[i]<<'\n';
    }

    
    
}
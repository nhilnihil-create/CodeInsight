#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e16+18;
const ll MAX=100005;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define sum(v) accumulate(ALL(v),0)
#define fi first
#define se second

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    int n;
    cin>>n;

    VVi to(n);

    int a,b;
    rep(i,n-1){
        cin>>a>>b;
        a--,b--;
        to[a].pb(b);
        to[b].pb(a);
    }
    Vi c(n);
    rep(i,n)cin>>c[i];
    sort(ALL(c));
    reverse(ALL(c));

    int ans = 0;

    rep(i,n){
        if(i==0)continue;
        ans += c[i];
    }

    priority_queue<int, vector<Pi>, function<bool(Pi, Pi)>> q([](Pi a, Pi b)->int {
        return a.first>b.first;
    });
    //q fi rank se 接点

    q.push(mp(0,0));

    vector<Pi> pos; // fi 接点 se 割当


    Vi parent(n,-1);

    cout<<ans<<endl;
    int cnt = 0;
    while (!q.empty()){
        Pi now = q.top();
        q.pop();
        pos.emplace_back(now.se,c[cnt]);
        cnt++;
        Each(v,to[now.se]){
            if(v==parent[now.se])continue;
            parent[v]=now.se;
            q.push(mp(now.first+1,v));
        }
    }

    sort(ALL(pos));
    rep(i,n){
        cout<<pos[i].se<<" ";
    }
    cout<<endl;

    return  0;
}

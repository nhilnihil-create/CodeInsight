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

    ll n,k;
    cin>>n>>k;
    vector<Pi> ss;

    priority_queue<ll, vector<P>, function<bool(P, P)>> q([](P a, P b)->ll {
        return a.first>b.first;
    });

    rep(i,n){
        int t,d;
        cin>>t>>d;
        t--;
        ss.emplace_back(d,t);
    }
    sort(ALL(ss));
    reverse(ALL(ss));


    map<ll,ll> mp;
    ll d=0;

    vector<Pi> cng;
    rep(i,n){
        Pi &now =ss[i];
        if(i<=k-1){
            d += now.fi;
            mp[now.se]++;
            if(mp[now.se]>1){
                q.push(mp(now.fi,now.se));
            }
        }else{
            cng.emplace_back(mp(now.fi,now.se));
        }
    }


    sort(ALL(cng));
    reverse(ALL(cng));

    ll ans=mp.size()*mp.size()+d;

    rep(i,cng.size()){
        if(q.empty()){
            break;
        }

        Pi &now = cng[i];
        if(mp[now.se]>0){
            continue;
        }

        mp[now.se]++;
        Pi del = q.top();
        d -= del.fi;
        q.pop();
        d += now.fi;
        ll x = mp.size()*mp.size()+d;
        ans = max(ans, x);
    }
    
    cout<<ans<<endl;
    return  0;
}

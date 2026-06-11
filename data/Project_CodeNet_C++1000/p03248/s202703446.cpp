#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)((n)-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p){
    return o << "(" << p.first << ", " << p.second << ")";
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    string s; cin >> s;
    int n = s.size();

    if(s[n-1] == '1' || !(s[0] == '1' && s[n-2] == '1')){
        cout << -1 << endl;
        return 0;
    }
    rep(i,n/2){
        if(s[i] != s[n-2-i]){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<pii> edges;
    int l,r;
    if(n % 2 == 1){
        if(s[n/2-1] == '1'){
            l = n/2 - 1, r = n/2 + 1;
            edges.emplace_back(l,l+1);
            edges.emplace_back(l+1,l+2);
        }else{
            l = n/2 - 1, r = n/2 - 1;
            edges.emplace_back(l,l+1);
            edges.emplace_back(l,l+2);
        }
    }else{
        if(s[n/2-1] == '1'){
            l = n/2 - 1, r = n/2;
            edges.emplace_back(l,l+1);
        }else{
            l = n/2 - 1, r = n/2 - 1;
            edges.emplace_back(l,l+1);
        }
    }
    rep(i,n/2-1){
        int vl = n/2-2-i;
        int vr = (n+1)/2+1+i;
        edges.emplace_back(l,vl);
        edges.emplace_back(r,vr);
        if(s[vl] == '1'){
            l = vl; r = vr;
        }
    }
    for(pii edge : edges){
        cout << edge.fi+1 << " " << edge.se+1 << endl;
    }
    return 0;
}
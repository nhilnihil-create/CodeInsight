#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define ll __int128

using namespace std;

template<typename S,typename T>auto&operator<<(auto&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(auto&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(auto&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(auto&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(auto&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}};
template<typename S,typename T,typename U>
auto& operator<<(auto& o,TRI<S,T,U>& t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 200005;

ll x[MAX_N], sm[MAX_N];

using LL = __int128;

istream& operator>>(istream& is, LL& v)
{
    string s;
    is >> s;
    v = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (isdigit(s[i])) { v = v * 10 + s[i] - '0'; }
    }
    if (s[0] == '-') { v *= -1; }
    return is;
}

ostream& operator<<(ostream& os, const LL& v)
{
    if (v == 0) { return (os << "0"); }
    LL num = v;
    if (v < 0) {
        os << '-';
        num = -num;
    }
    string s;
    for (; num > 0; num /= 10) { s.push_back((char)(num % 10) + '0'); }
    reverse(s.begin(), s.end());
    return (os << s);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, X;
    cin >> n >> X;
    rep(i,n){
        cin >> x[i];
        sm[i+1] = sm[i] + x[i];
    }
    ll ans = (1LL << 62);
    srep(k,1,n+1){
        ll res = 0;
        for(int j = 0;; j++){
            if(j == 0) res += 5*(sm[n-k*j] - sm[max((ll)0, n-k*j-k)]);
            else res += (2*j+3)*(sm[n-k*j] - sm[max((ll)0, n-k*j-k)]);
            if(n-k*j-k <= 0) break;
        }
        cmn(ans, res+(n+k)*X);
    }
    cout << ans << "\n";
    return 0;
}

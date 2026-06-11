#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

constexpr ll D = 1e16;

ll digit(ll t){
    ll res=0;
    while(t){
        res += t%10;
        t/=10;
    }
    return res;
}

int main(){
    ll k;
    cin >> k;

    set<ll> cand;
    ll base = 0;
    for(ll i=0;i<=13;i++){  // 下i桁が9
        for(int j=0;j<=1000;j++){
            cand.insert(j*(base+1)+base);
            if(j*(base+1)+base >= D) break;
        }
        base = base * 10 + 9;
    }
    cand.erase(0);

    //int cnt = 20;
    //for(auto v : cand){
    //    cout << v << endl;
    //    if(--cnt==0) return 0;
    //}

    vector<ll> v(cand.begin(),cand.end());
    vector<pair<ll,ll>> val(cand.size());
    for(int i=0;i<cand.size();i++) val[i] = make_pair(v[i],digit(v[i]));

    vector<bool> valid(cand.size(),true);
    for(int i=cand.size()-2;i>=0;i--){
        if(val[i].fi * val[i+1].se > val[i].se * val[i+1].fi){
            val[i] = val[i+1];
            valid[i] = false;
        }
    }

    set<ll> ans;
    for(int i=0;i<valid.size();i++){
        if(valid[i]){
            ans.insert(v[i]);
        }
    }

    for(auto a : ans){
        cout << a << endl;
        if(--k == 0) break;
    }
} 

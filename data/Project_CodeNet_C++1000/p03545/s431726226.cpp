#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

void solve(){
    int a,b,c,d;
    string s;
    cin >> s;
    a=s[0]-'0';
    b=s[1]-'0';
    c=s[2]-'0';
    d=s[3]-'0';

    rp(i,8){
        bool op1=false,op2=false,op3=false;
        if(i&1) op1=true;
        if(i&2) op2=true;
        if(i&4) op3=true;
        int sum=a;
        if(op1) sum+=b;
        else sum-=b;
        if(op2) sum+=c;
        else sum-=c;
        if(op3) sum+=d;
        else sum-=d;
        if(sum==7){
            cout << a;
            if(op1) cout << '+';
            else cout << '-';
            cout << b;
            if(op2) cout << '+';
            else cout << '-';
            cout << c;
            if(op3) cout << '+';
            else cout << '-';
            cout << d << "=7" << endl;
            return;
        }
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}
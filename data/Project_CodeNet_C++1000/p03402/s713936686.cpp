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
    int a,b;
    cin >> a >> b;
    if(a==1){
        cout << (b/50+1)*2+1 <<" " << 100 << endl;
        rp(i,100) cout << ".";
        cout << endl;
        int ctr=0;
        while(b>0){
            ctr++;
            b--;
            cout << "#.";
            if(ctr%50==0){
                cout << endl;
                rp(i,100) cout << ".";
                cout << endl;
            }
        }
        cout << "..";
        ctr++;
        while(ctr%50!=0){
            cout << "..";
            ctr++;
        }
        cout << endl;
        rp(i,100) cout << ".";
        cout << endl;
        return;
    }
    bool one=false;
    if(a%50==1) one=true;
    int m=min(a,b)-1;
    cout << m/50+(a-m/50*50+48)/50*2+(a%50==1?2:1)+(b-(max(0,m/50-1))*50+49)/50*2 << " " << 100 << endl;
    bool col=true;
    rp(i,m/50){
        rp(j,50){
            if(col)
            cout << ".#";
            else
            cout << "#.";
        }
        a-=50;
        if(i<m/50-1)b-=50;
        cout << endl;
        col^=true;
    }
    
    rp(i,100) cout << "#";
    cout << endl;
    int ctr=0;
    while(a>1){
        cout << "#.";
        a--;
        ctr++;
        if(ctr%50==0){
            cout << endl;
            rp(i,100) cout << "#";
            cout << endl;
        }
    }
    while(ctr%50!=0){
        cout << "##";
        ctr++;
    }
    if(!one)cout << endl;
    rp(i,100) cout << "#";
    cout << endl;
    rp(i,100) cout << ".";
    cout << endl;
    if(b%50==1){
        rp(i,100) cout << ".";
        cout << endl;
    }
    
    ctr=0;
    while(b>1){
        cout << ".#";
        b--;
        ctr++;
        if(ctr%50==0){
            cout << endl;
            rp(i,100) cout << ".";
            cout << endl;
        }
    }
    while(ctr%50!=0){
        cout << "##";
        ctr++;
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}
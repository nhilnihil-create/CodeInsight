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

int main(){
    vector<vi> sch(26,vi(0)),tch(26,vi(0));
    string s,t;
    cin >> s >> t;
    int si=s.size();
    rp(i,si){
        char ch=s.at(i);
        sch.at(ch-'a').push_back(i);
    }
    rp(i,si){
        char ch=t.at(i);
        tch.at(ch-'a').push_back(i);
    }
    sort(all(sch));
    sort(all(tch));
    bool ok=true;
    rp(i,26){
        int n=sch[i].size();
        int m=tch[i].size();
        if(n!=m){
            ok=false;
            break;
        }
        rp(j,n){
            if(sch[i][j]!=tch[i][j])
            {
                ok=false;
                break;
            }
        }
    }
    Yes(ok);
    return 0;
}
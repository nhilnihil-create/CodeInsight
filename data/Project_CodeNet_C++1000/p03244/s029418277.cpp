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
    int n;
    cin >> n;
    vi v1((n+1)/2),v2(n/2);
    rp(i,n/2){
        cin >> v1.at(i) >> v2.at(i);
    }
    if(n&1) cin >> v1.at((n-1)/2);
    priority_queue<P> que1,que2;
    sort(all(v1)); sort(all(v2));
    int ctr=1;
    rp(i,(n+1)/2-1){
        if(v1.at(i)==v1.at(i+1)) ctr++;
        else{
            que1.push(mp(ctr,v1.at(i)));
            ctr=1;
        }
    }
    que1.push(mp(ctr,v1.back()));
    ctr=1;
    rp(i,n/2-1){
        if(v2.at(i)==v2.at(i+1)) ctr++;
        else{
            que2.push(mp(ctr,v2.at(i)));
            ctr=1;
        }
    }
    que2.push(mp(ctr,v2.back()));
    int t[2][2];
    t[0][0]=que1.top().first; t[0][1]=que1.top().second;
    t[1][0]=que2.top().first; t[1][1]=que2.top().second;
    que1.pop(); que2.pop();
    if(t[0][1]!=t[1][1]){
        print(n-t[0][0]-t[1][0]);
    }
    else if(que1.empty()){
        if(que2.empty()){
            print(n/2);
        }
        else{
            print(n/2-que2.top().first);
        }
    }
    else if(que2.empty()){
        print((n+1)/2-que1.top().first);
    }
    else{
        print(n-max(t[0][0]+que2.top().first,t[1][0]+que1.top().first));
    }
    return 0;
}
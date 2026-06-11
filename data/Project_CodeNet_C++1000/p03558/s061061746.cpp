#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

// dp[x]:= Kで割った余りがxの集合の中で、桁数和最小
ll dp[100005];

int main(){
    int K;
    cin >> K;

    vector<ll> dp(100005, longinf);

    priority_queue<P_ii, vector<P_ii>, greater<P_ii>> que;
    for(ll i = 1; i <= 9; i++){
        chmin(dp[i % K], i);
        que.push({dp[i % K], i});
    }

    while(!que.empty()){
        ll x = que.top().second;
        ll cost = que.top().first; 
        que.pop();

        if(dp[x] != cost) continue;

        REP(y, 10){
            if(dp[(10 * x + y) % K] > cost + y){
                dp[(10 * x + y) % K] = cost + y;
                que.push({dp[(10 * x + y) % K], (x * 10 + y) % K});
            }
        }
    }

    cout << dp[0] << endl;


    return 0;
}
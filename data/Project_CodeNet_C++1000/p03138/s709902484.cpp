#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<functional>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.20f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define cotu cout
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll dp[60][2];
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n;
    ll K;
    cin >> n >> K;
    ll A[100100];
    rep(i,0,n) cin >> A[i];
    rep(i,0,60){
      dp[i][0] = -1;
      dp[i][1] = -1;
    }
    dp[59][0] = 0;
    for(int i=58;i>=0;i--){
        ll add = 1LL << i;
        ll cnt = 0;
        rep(i,0,n) if(A[i] & add) cnt++;
        if(dp[i+1][1] >= 0){
                chmax(dp[i][1], dp[i+1][1] + add * max(n-cnt, cnt));
        }
        if(dp[i+1][0] >= 0){
            if(K & (1LL << i)){
              chmax(dp[i][1], dp[i+1][0] + add * cnt);
              chmax(dp[i][0], dp[i+1][0] + add * (n-cnt));
            }else{
              chmax(dp[i][0], dp[i+1][0] + add * cnt);
            }   
        }
    }

    ll ans = max(dp[0][0], dp[0][1]);
    cout << ans << endl;
    return 0;
}
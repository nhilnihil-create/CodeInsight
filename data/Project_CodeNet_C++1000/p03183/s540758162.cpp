# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(13);
    }
}INIT;


int main(){
    int n;
    cin >> n;
    vector<LL> w(n), s(n), v(n), order(n);
    REP(i, n)cin >> w[i] >> s[i] >> v[i];
    int maxl = (*max_element(ALL(s)) + *max_element(ALL(w))) + 1;
    REP(i, n)order[i] = i;
    sort(ALL(order), [&](int a, int b){return w[a] + s[a] < w[b] + s[b];});
    vector<vector<LL>> dp(n + 1, vector<LL>(maxl, 0));
    REP(i, n){
        int cur = order[i];
        REP(j, maxl)dp[i + 1][j] = dp[i][j];
        for(int j = 0;j <= s[cur];j++){
            if(j + w[cur] < maxl)dp[i + 1][j + w[cur]] = max(dp[i + 1][j + w[cur]], dp[i][j] + v[cur]);
        }
    }
    LL ans = 0;
    REP(i, maxl)ans = max(ans, dp[n][i]);
    cout << ans << endl;
}

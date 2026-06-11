# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
typedef pair<LL, LL> pii;
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
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)

LL k;

LL calc(LL x){
    LL y = x + 1;
    string v = to_string(y);
    map<LL, bool>cand;
    for(int i = v.size();i > 0;i--){
        LL a = 0,b = 1, c;
        REP(j, i - 1){
            a *= 10;
            a += v[j] - '0';
        }
        for(int j = i - 1;j < (int)v.size(); j++){
            a *= 10;
            b *= 10;
        }
        b /= 10;
        c = b - 1;
        for(int j = v[i - 1] - '0'; j <= 9;j++){
            cand[a + j * b + c] = true;
        }
    }
    vector<pair<double, LL>> w;
    for(auto it = cand.begin();it != cand.end(); it++){
        w.emplace_back(make_pair((double)it->first/d_sum(it->first), it->first));
    }
    sort(ALL(w));
    return w[0].second;
}

int main(){
    INIT;
    cin >> k;
    LL num = 0;
    while(k > 0){
        num = calc(num);
        cout << num << endl;
        k--;
    }
}
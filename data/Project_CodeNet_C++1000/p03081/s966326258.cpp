# include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
template<typename T>vector<T> make_v(size_t a){ return vector<T>(a); }
template<typename T,typename... Ts>auto make_v(size_t a, Ts... ts){ return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }
template<typename T,typename V>typename enable_if<is_class<T>::value==0>::type fill_v(T &t, const V &v){ t = v; }
template<typename T,typename V>typename enable_if<is_class<T>::value!=0>::type fill_v(T &t, const V &v){ for(auto &e : t) fill_v(e, v); }
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

int n, q;
string s;
char t[202020];
char d[202020];

bool calc1(int cur){
    REP(i, q){
        if(t[i] == s[cur]){
            if(d[i] == 'L')cur--;
            if(d[i] == 'R')cur++;
        }
        if(cur == n + 1)return false;
    }
    return cur == 0;
}

bool calc2(int cur){
    REP(i, q){
        if(t[i] == s[cur]){
            if(d[i] == 'L')cur--;
            if(d[i] == 'R')cur++;
        }
        if(cur == 0)return false;
    }
    return cur == n + 1;
}

int main(){
    INIT;
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    REP(i, q){
        cin >> t[i] >> d[i];
    }
    int l1 = 0, r1 = n + 1;
    while(r1 - l1 > 1){
        int mid = (l1 + r1)/2;
        if(calc1(mid)){
            l1 = mid;
        }else{
            r1 = mid;
        }
    }
    int l2 = 0, r2 = n + 1;
    while(r2 - l2 > 1){
        int mid = (l2 + r2)/2;
        if(calc2(mid)){
            r2 = mid;
        }else{
            l2 = mid;
        }
    }
    cout << n - l1 - (n - r2 + 1) << endl;
}
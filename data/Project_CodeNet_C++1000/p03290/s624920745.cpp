#pragma region header
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define resort(v) sort((v).rbegin(), (v).rend())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
using ll = long long;
using P = pair<int, int>;
/* ----------------よく使う数字や配列----------------- */
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
constexpr ll mod = 1e9+7;
constexpr int inf = INT32_MAX/2;
constexpr ll INF = LLONG_MAX/2;
constexpr long double eps = DBL_EPSILON;
constexpr long double pi = 3.141592653589793238462643383279;
/* ----------------------end----------------------- */

/* --------------------テンプレート------------------ */
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
/* ----------------------end----------------------- */

/* --------------------ライブラリ-------------------- */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i % mod;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isprime(int n) { //素数判定
    if(n==1)return false;
    if(n==2)return true;
    for(int i = 2;i<=sqrt(n);i++) {
        if(n%i==0) return false;
    }
    return true;
}
/* ----------------------end----------------------- */
#pragma endregion
signed main() {
    int d,g;cin >> d >> g;
    vector<P> v(d);
    rep(i, d) cin >> v[i].first >> v[i].second;
    int mi = inf;
    rep(bit,(1<<d)) {
        bool ok = true;
        int score=0,count=0;
        rep(i, d) {
            if(1&(bit>>i)) {
                score+=v[i].first*100*(i+1)+v[i].second;
                count+=v[i].first;
            }
        }
        if(score<g) {
            int i = d-1;
            while(score<g) {
                if(i==-1){
                    ok=false;
                    break;
                }
                int cnt = 0;
                if(1&(bit>>i)) {
                    i--;
                    // if(bit==2)cout << "OK\n";
                    continue;
                }
                cnt = ((g-score)+(100*(i+1))-1)/(100*(i+1));
                chmin(cnt,v[i].first);
                count+=cnt;
                score+=cnt*(100*(i+1));
                i--;
                /*if(bit==2) {
                    cout << "OK\n";
                    cout << cnt << endl;
                    cout << count << endl;
                    cout << score << endl;
                    cout << i << endl;
                }*/
                // if(bit==0) cout << count << ' ' << score << endl;
            }
        }
        if(ok)chmin(mi,count);
        /*if(bit==2) {
            cout << bitset<2>(bit) << endl;
            cout << count << endl;
            cout << score << endl;
        }*/
        /*if(count==8){
            cout << bitset<2>(bit) << endl;
            cout << count << endl;
            cout << score << endl;
        }*/
    }
    cout << mi << endl;
    return 0;
}
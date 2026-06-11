#pragma region header
#include <bits/stdc++.h>
using namespace std;
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
    return (fact(i - 1)) * i;
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
/* ----------------------end----------------------- */
#pragma endregion
int main() {
    /*int n;string s;cin >> n >> s;
    int white = 0;
    int black = 0;
    int count = 0;
    rep(i, n) {
        if(s[i]=='.') white++;
        else black++;
    }*/
    /*rev(i, n) {
        if(s[i]=='.') {
            // white++;
            if(s[i-1]=='#') {
                count++;
                s[i-1]='.';
            }
        }
    }
    cout << min(white,count) << endl;*/
    int n;string s;cin >> n >> s;
    vi black(n+1),white(n+1);
    rep(i, n) {
        if(s[i]=='#') black[i+1]++;
        // else white[n-i]++;
        black[i+1]+=black[i];
        // white[n-i-1]+=white[n-i];
    }
    rev(i, n) {
        if(s[i]=='.') white[i]++;
        white[i]+=white[i+1];
    }

    int mi = inf;
    /*for(auto p:black)cout << p << ' ';
    cout << endl;
    for(auto p:white)cout << p << ' ';
    cout << endl;*/
    rep(i, n+1) {
        chmin(mi,black[i]+white[i]);
    }
    cout << mi << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a/gcd(a, b) * b;
}

string replaceOtherStr(std::string &replacedStr, std::string from, std::string to) {
    const unsigned int pos = replacedStr.find(from);
    const int len = from.length();
 
    if (pos == std::string::npos || from.empty()) {
        return replacedStr;
    }
 
    return replacedStr.replace(pos, len, to);
}

string replaceAll(std::string &replacedStr, std::string from, std::string to) {
    unsigned int pos = replacedStr.find(from);
    int toLen = to.length();
 
    if (from.empty()) {
        return replacedStr;
    }
 
    while ((pos = replacedStr.find(from, pos)) != std::string::npos) {
        replacedStr.replace(pos, from.length(), to);
        pos += toLen;
    }
    return replacedStr;
}

int main()
{
    cout << fixed << setprecision(15);
    string s;
    cin >> s;

    // cout << s << endl;

    // string s = "a, b, c";     // 置換対象の文字列
    string target = "BC";     // 検索文字列
    string replacement = "D"; // 置換文字列

    if (!target.empty()) {
        string::size_type pos = 0;
        while ((pos = s.find(target, pos)) != std::string::npos) {
            s.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
    }

    ll N = s.length();
    ll acount = 0;
    ll ans = 0;
    REP(i, N){
        if(s[i] == 'A'){
            acount++;
        }
        else if(s[i] == 'D'){
            ans += acount;
        }
        else{
            acount = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
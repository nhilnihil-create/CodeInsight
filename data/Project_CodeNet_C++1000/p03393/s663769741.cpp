#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void solve() {
    string s;
    cin >> s;
    map<char,int> mp;

    // 初期化
    REP(i,26) mp[(char)(i+'a')] = 0;
    // count
    for(const auto &it: s) mp[it]++;

    bool have_zero = false;
    for (const auto &it: mp) {
        if (it.second == 0) {
            have_zero = true;
            break;
        }
    }
    if (!have_zero) {
        // ある文字において、それよりお大きく、使われていないものを後ろから見つける
        REPR(i,24) {
            // 初期化
            REP(j,26) mp[(char)(j+'a')] = 0;
            // カウント
            REP(j,i) mp[s[j]]++;
            for (const auto &it: mp) {
                if ( (it.first > s[i]) && (it.second == 0)) {
                    // 答えの作成
                    REP(j,i) cout << s[j];
                    cout << it.first << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
        return;
    }

    // 0になっている部分を探す
    char zero_c = '0';
    for (const auto &it: mp) {
        if (it.second == 0) {
            zero_c = it.first;
            break;
        }
    }

    s.push_back(zero_c);

    cout << s << endl;
}

int main() {
    solve();
    return 0;
}

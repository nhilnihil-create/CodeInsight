#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
// https://ykmaku.hatenablog.com/entry/2018/09/03/153250
int main() {
    int a, b;
    cin >> a >> b;
    //しろがA個の連結成分 less than 500
    //くろがB個の連結成分 less than 500
    string s[100];
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(i < 50)
                s[i].push_back('.');
            else
                s[i].push_back('#');
        }
    }
    int cnt = 0;
    for(int i = 0; i < 50; i += 2) {
        for(int j = 0; j < 100; j += 2) {
            if(cnt == b - 1) {
                break;
            }
            s[i][j] = '#';
            cnt++;
        }
    }
    cnt = 0;
    for(int i = 51; i < 100; i += 2) {
        for(int j = 0; j < 100; j += 2) {
            if(cnt == a - 1) {
                break;
            }
            s[i][j] = '.';
            cnt++;
        }
    }
    cout << 100 << " " << 100 << endl;
    for(int i = 0; i < 100; i++) {
        cout << s[i] << endl;
    }

    return 0;
}
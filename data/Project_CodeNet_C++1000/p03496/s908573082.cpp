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

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    REP(i, N) { cin >> a[i]; }
    int ma = *max_element(a.begin(), a.end());
    int pm = a[0];
    int mindex = max_element(a.begin(), a.end()) - a.begin();
    int mi = *min_element(a.begin(), a.end());
    int miindex = min_element(a.begin(), a.end()) - a.begin();
    int cnt = 0;
    std::stringstream buffer;
    if(mi >= 0) {
        for(int i = 1; i < N; i++) {
            cnt++;
            buffer << i << " " << i + 1 << endl;
        }
    } else if(ma <= 0) {
        for(int i = N - 1; i >= 1; i--) {
            cnt++;
            buffer << i + 1 << " " << i << endl;
        }
    } else if(abs(mi) > abs(ma)) {
        //すべて負にする
        // cout << "a" << endl;
        for(int i = 0; i < N; i++) {
            cnt++;
            buffer << miindex + 1 << " " << i + 1 << endl;
        }
        for(int i = N - 1; i >= 1; i--) {
            cnt++;
            buffer << i + 1 << " " << i << endl;
        }
    } else {
        for(int i = 0; i < N; i++) {
            cnt++;
            buffer << mindex + 1 << " " << i + 1 << endl;
        }
        for(int i = 1; i < N; i++) {
            cnt++;
            buffer << i << " " << i + 1 << endl;
        }
    }

    cout << cnt << endl;
    cout << buffer.str() << endl;
    return 0;
}
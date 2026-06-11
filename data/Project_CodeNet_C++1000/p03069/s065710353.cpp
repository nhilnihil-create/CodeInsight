#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
string S;

int main() {
    cin >> N >> S;
    ll tmp = 0;
    for(auto c : S) {
        if(c == '.') tmp++;
    }
    ll ans = tmp;
    for(auto c : S) {
        if(c == '.') tmp--;
        else tmp++;
        chmin(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
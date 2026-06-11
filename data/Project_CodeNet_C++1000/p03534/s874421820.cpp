#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int a, b, c;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'a') a++;
        if(S[i] == 'b') b++;
        if(S[i] == 'c') c++;
    }
    if(max(a, max(b, c)) - min(a, min(b, c)) <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

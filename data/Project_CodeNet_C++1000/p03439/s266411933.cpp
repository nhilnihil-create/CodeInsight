#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int ask(int i) {
    string s;
    cout << i << endl;
    cin >> s;
    if(s == "Vacant") {
        return 0;
    } else if(s == "Male") {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    int n;
    cin >> n;
    int l = ask(0);
    if(l == 0) {
        return 0;
    }
    int ok = 0, ng = n;
    while(1) {
        int mid = (ok + ng) / 2;
        int r = ask(mid);
        if(r == 0) {
            return 0;
        }
        if((l == r && mid % 2 == 0) || (l != r && mid % 2)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return 0;
}
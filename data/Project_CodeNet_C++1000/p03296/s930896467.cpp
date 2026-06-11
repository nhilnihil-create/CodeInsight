#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std; 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;
 
#define REP(inc, bgn, end) for (int inc = bgn; inc < end; inc++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,0,n) cin >> a[i];

    int cnt = 0;
    REP(i,1,n) {
        if (a[i-1] == a[i]) {
            cnt++;
            a[i] = 0;
        }
    }

    cout << cnt << endl;
}
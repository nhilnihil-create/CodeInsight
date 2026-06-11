#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
 
// cout<<fixed<<setprecision(10);
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}


int main() {
    int n;
    cin >> n;
    string ans;
    if(n >= 1000) {
        ans = "ABD";
    } else {
        ans = "ABC";
    }
    cout << ans << endl;
}

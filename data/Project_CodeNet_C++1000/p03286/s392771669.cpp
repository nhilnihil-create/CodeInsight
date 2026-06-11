#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const ll inf = 1e18;
const int mod = 1e5;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    if (n == 0) {cout << 0 << endl; return 0;}
    vint ans;
    int keta = 1;
    while (n != 0) {
        if (n % 2 != 0) {
            ans.push_back(1);
            n -= 1;
        }
        else ans.push_back(0);
        n /= -2;
    }
    reverse(ans.begin(),ans.end());
    rep(i,ans.size()) cout << ans[i];
    cout << endl;
}
#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

int solve(int a) {
    int res = 0;
    while(a > 0) {
        res += a % 10;
        a /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int ans = INF;
    rrep(i, n - 1) {
        int a = i, b = n - a;
        ans = min(ans, solve(a) + solve(b));
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 10**9

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    int ans1 = min(a,b);
    int ans2 = n >= a+b ? 0:(a+b)-n;
    cout << ans1 << " " << ans2 << endl;
}
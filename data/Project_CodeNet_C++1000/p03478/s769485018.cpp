#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i, 1, n+1){
        int sum = 0;
        string x = to_string(i);
        rep(j, 0, x.size()) sum += x[j] - '0';
        if(a <= sum && sum <= b) ans += i;
    }
    cout << ans << endl;
    return 0;
}

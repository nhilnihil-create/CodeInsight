#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    rep(i, a, b+1){
        string s = to_string(i);
        string t = s;
        reverse(s.begin(), s.end());
        if(s == t) ans++;
    }
    cout << ans << endl;
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int a, b, c, x, y;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int cnt = min(x, y);
    x -= cnt; y -= cnt;
    ans += min(a + b, c + c)*cnt;
    ans += min(a, c + c)*x;
    ans += min(b, c + c)*y;
    cout << ans << E;
    //system("pause");
    return 0;
}
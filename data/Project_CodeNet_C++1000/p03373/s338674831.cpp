#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll answer = 1e12;
    ll maxC = max(X, Y) * 2;
    for (int i = 0; i <= maxC; i += 2)
    {
        answer = min(answer, A * max(0LL, X - i / 2) + B * max(0LL, Y - i / 2) + C * i);
    }
    cout << answer << endl;
    return 0;
}

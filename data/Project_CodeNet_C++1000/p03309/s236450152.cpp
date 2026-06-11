#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(0, i, N)
    {
        int a;
        cin >> a;
        A.at(i) = a - i + 1;
    }
    sort(all(A));
    ll ans = 0;
    ll ans1 = 0, ans2 = 0;
    if (N % 2 == 0 || N == 1)
    {
        rep(0, i, N)
        {
            ans += abs(A.at(i) - A.at(N / 2));
        }
    }
    else
    {
        rep(0, i, N)
        {
            ans1 += abs(A.at(i) - A.at(N / 2));
            ans2 += abs(A.at(i) - A.at(N / 2 + 1));
        }
        ans = min(ans1, ans2);
    }

    cout << ans << endl;
}
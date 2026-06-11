// AtCoder Beginner Contest 092 - Problem A: Travelling Budget (https://atcoder.jp/contests/abc092/tasks/abc092_a)
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    auto ans = min(A, B) + min(C, D);

    cout << ans << '\n';

    return 0;
}

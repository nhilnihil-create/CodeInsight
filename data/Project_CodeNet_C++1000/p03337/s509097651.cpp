#include <bits/stdc++.h>

using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    auto ans = max({A + B, A - B, A * B});
    cout << ans;

    return 0;
}
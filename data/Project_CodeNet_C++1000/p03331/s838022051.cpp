#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum_x(int x)
{
    int sum = 0; // 0で初期化を忘れない。
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    int ans = N;

    for (int i = 1; i < N; ++i)
    {
        int A = i;
        int B = N - i;
        int temp = sum_x(i) + sum_x(B);
        ans = min(temp, ans);
    }
    cout << ans << endl;
}

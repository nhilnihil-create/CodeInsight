#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    // 答え
    int ret = 0;

    for (int i = 1; i <= N; ++i)
    {
        int a = i;

        // 各桁の和を求める
        int sum = 0;
        while (a > 0)
        {
            sum += a % 10;
            a /= 10;
        }

        if (A <= sum && sum <= B)
        {
            ret += i;
        }
    }

    cout << ret << endl;

    return 0;
}

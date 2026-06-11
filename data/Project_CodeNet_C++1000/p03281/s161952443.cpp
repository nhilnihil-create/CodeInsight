#include <bits/stdc++.h>
using namespace std;

int count_divisors(int N)
{
    int cnt = 0;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            ++cnt;
            if (N / i != i)
                ++cnt;
        }
    }
    return cnt;
}

int	main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i += 2) {
        if (count_divisors(i) == 8)
            ++cnt;
    }
    cout << cnt << endl;
}

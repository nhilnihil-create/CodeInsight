#include <bits/stdc++.h>
using namespace std;

int digit_sum(int num) {
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int minv = (1<<20), v;
    for (int i = 1; i < N; i++)
    {
        int j = N - i;
        v = digit_sum(i) + digit_sum(j);
        minv = min(minv, v);
    }

    cout << minv << endl;
}
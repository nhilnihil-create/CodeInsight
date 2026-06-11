#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long long x[N];
    long long s;
    cin >> s;
    s *= -1;
    x[0] = 0;
    for (int i = 1; i < N; i++)
    {
        cin >> x[i];
        x[i] += s;
    }

    long ans = (long)1e10;
    for (int i = 0; i + K - 1 < N; i++)
    {
        long tmp = x[i + K - 1] - x[i] + min(abs(x[i] - s), abs(x[i + K - 1] - s));
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
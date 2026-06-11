#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int main()
{
    int N, K;

    int ans = 0, max = 0;

    cin >> N >> K;

    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++)
        b[i] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        b[a[i] - 1]++;
    }

    sort(b.begin(), b.end(), greater<int>()); // 降順（大きい順）でソー

    for (int i = K; i < N; i++)
    {
        ans += b[i];
    }

    cout << ans << endl;

    return 0;
}
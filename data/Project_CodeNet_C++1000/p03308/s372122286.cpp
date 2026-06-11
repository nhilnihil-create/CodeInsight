#include <bits/stdc++.h>
using namespace std;

// 最小値と最大値を覚えておいて、その差をとればよいはず。

int main() {
    int N;
    cin >> N;

    int min_n= 1000000001, max_n = 0;
    int current_n;
    for (int i = 0; i < N; i++)
    {
        cin >> current_n;
        min_n = min(min_n, current_n);
        max_n = max(max_n, current_n);
    }

    cout << max_n - min_n << endl;
}
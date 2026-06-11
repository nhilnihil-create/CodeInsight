#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    int cnt = 0; // ドーナツの個数

    int A[N];
    int m;
    int min_m = 100001;
    for (int i = 0; i < N; i++)
    {
        // 一番コストが低いものを記憶しておく。
        cin >> m;
        if (min_m > m)
            min_m = m;

        // とりあえず一つずつつくる。
        X -= m;
        cnt++;
    }

    while (X >= min_m)
    {
        cnt++;
        X -= min_m;
    }
    cout << cnt << endl;
}
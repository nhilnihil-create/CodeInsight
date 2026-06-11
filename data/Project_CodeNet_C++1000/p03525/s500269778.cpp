#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
    int N; cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; ++i)
        cin >> D[i];
    sort(D.begin(), D.end(), greater<int>());
    int res = 0;
    // 高橋君から見て、N人全員が同じ側
    int tmp = 24 - D[0];
    for (int i = 0; i < N - 1; ++i)
        tmp = min(tmp, D[i] - D[i + 1]);
    tmp = min(tmp, D[N - 1]);
    res = max(res, tmp);
    // 初めて違う方向に割り当てたのが人i
    for (int i = 1; i < N; ++i){
        tmp = 24 - (D[0] + D[i]);
        for (int j = 0; j < i - 1; ++j)
            tmp = min(tmp, D[j] - D[j + 1]);
        for (int j = i; j + 2 < N; j += 2)
            tmp = min(tmp, D[j] - D[j + 2]);
        for (int j = i - 1; j + 2 < N; j += 2)
            tmp = min(tmp, D[j] - D[j + 2]);
        tmp = min(tmp, D[N - 1]);
        if (N > 1) tmp = min(tmp, D[N - 2]);
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}
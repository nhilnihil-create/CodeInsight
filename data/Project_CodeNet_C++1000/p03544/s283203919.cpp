#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int64_t> L(N + 1);
    L[0] = 2LL;
    L[1] = 1LL;
    for (int i = 2; i <= N; i++){
        L[i] = L[i - 1] + L[i - 2];
    }
    cout << L[N] << endl;
}
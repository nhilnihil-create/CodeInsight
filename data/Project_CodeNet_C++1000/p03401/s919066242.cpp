#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    //A[i]とA[i+1]の差をベクトルとして管理=> diff1
    //A[i]とA[i+2]の差もベクトルとして管理=> diff2
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> diff1(N+1);
    vector<int> diff2(N);
    for (int i = 0; i <= N; i++) {
        if (i == 0) diff1[i] = abs(A[i]);
        if (i == N) diff1[i] = abs(A[N-1]);
        else diff1[i] = abs(A[i]-A[i-1]);
    }
    for (int i = 0; i < N; i++) {
        if (i == 0) diff2[i] = abs(A[i+1]);
        if (i == N-1) diff2[i] = abs(A[i-1]);
        else diff2[i] = abs(A[i+1]-A[i-1]);
    }
    ll sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += diff1[i];
    }

    //答え
    for (int i = 0; i < N; i++) {
        ll ans = sum;
        ans -= diff1[i];
        ans -= diff1[i+1];
        ans += diff2[i];
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    int A[N], B[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    ll bigA = 0, bigB = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] > B[i])
            bigA += A[i] - B[i];
        else
            bigB += (B[i] - A[i]) / 2;
    }
    if(bigB >= bigA)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
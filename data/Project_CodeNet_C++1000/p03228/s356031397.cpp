#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int A[2], K; cin >> A[0] >> A[1] >> K;
    int i = 0;
    while (K--) {
        if (A[i] % 2) A[i]--;
        A[i] = A[i] / 2;
        A[!i] += A[i];
        i = !i;
    }
    cout << A[0] << ' ' << A[1] << '\n';
    return 0;
}
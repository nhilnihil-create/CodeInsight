#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;

const int MAX = 210000;;

int N;
int A[MAX], B[MAX], C[MAX];

int main() {
    while (cin >> N) {
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
        for (int i = 0; i < N; ++i) cin >> C[i];

        sort(A, A+N);
        sort(B, B+N);
        sort(C, C+N);
        long long res = 0;
        for (int i = 0; i < N; ++i) {
            long long a = lower_bound(A, A+N, B[i]) - A;
            long long c = C + N - upper_bound(C, C+N, B[i]);
            res += a * c;
        }
        cout << res << endl;
    }
}

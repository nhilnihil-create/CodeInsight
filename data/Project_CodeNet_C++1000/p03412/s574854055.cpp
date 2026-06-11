#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    for(int j=0; j<N; ++j) cin >> b[j];

    int res = 0;
    vector<int> A(N), B(N);
    
    for(int k=0; k<29; ++k) {
        int mask = (1 << (k + 1)) - 1;
        for(int i=0; i<N; ++i) {
            A[i] = a[i] & mask;
            B[i] = b[i] & mask;
        }
        sort(begin(B), end(B));

        int cnt = 0;
        for(int i=0; i<N; ++i) {
            if(A[i] <= (1 << k)) {
                cnt += lower_bound(begin(B), end(B), (1 << (k + 1)) - A[i])
                        - lower_bound(begin(B), end(B), (1 << k) - A[i]);
            } else {
                cnt += lower_bound(begin(B), end(B), (1 << (k + 1)) - A[i]) - begin(B);
                cnt += end(B) - lower_bound(begin(B), end(B), (1 << k) + (1 << (k + 1)) - A[i]);
            }
            cnt %= 2;
        }

        if(cnt) res += (1 << k);
    }
    
    cout << res << endl;
}
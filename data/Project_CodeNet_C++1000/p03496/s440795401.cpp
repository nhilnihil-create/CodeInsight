#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    auto ma = max_element(begin(A), end(A));
    auto mi = min_element(begin(A), end(A));

    cout << 2 * N - 2 << endl;
    if(abs(*ma) >= abs(*mi)) {
        int index = ma - begin(A) + 1;
        for(int i=1; i<=N; ++i) {
            if(i != index) cout << index << ' ' << i << endl;
        }
        for(int i=1; i<N; ++i) cout << i << ' ' << i + 1 << endl;
    } else {
        int index = mi - begin(A) + 1;
        for(int i=1; i<=N; ++i) {
            if(i != index) cout << index << ' ' << i << endl;
        }
        for(int i=N; i>1; --i) cout << i << ' ' << i - 1 << endl;
    }
}
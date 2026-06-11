#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    int res = 0;
    int ok = 0;
    int MIN = 1e9;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] < 0) {
            ok++;
        }
        if(abs(A[i]) < MIN) {
            MIN = abs(A[i]);
        }
        res+=abs(A[i]);
    }
    if(ok%2 == 0) {
        cout << res << endl;
    }
    else {
        cout << res-MIN*2 << endl;
    }
}
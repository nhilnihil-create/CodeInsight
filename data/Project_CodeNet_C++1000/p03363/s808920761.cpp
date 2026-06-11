#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>B(N+1);
    B[0] = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        B[i+1] = B[i]+A[i];
    }
    int ans = 0;
    int cnt = 1;
    sort(B.begin(),B.end());
    for(int i = 1; i <= N; i++) {
        if(B[i] == B[i-1]) {
            cnt++;
        }
        else {
            ans+=(cnt*(cnt-1))/2;
            cnt = 1;
        }
    }
    ans+=(cnt*(cnt-1))/2;
    cout << ans << endl;
}
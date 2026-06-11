#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int>l(N);
    vector<int>r(N);
    l[0] = A[0]; r[N-1] = A[N-1];
    for(int i = 1; i < N; i++) {
        l[i] = __gcd(l[i-1],A[i]);
        r[N-i-1] = __gcd(r[N-i],A[N-i-1]);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            ans = max(ans,r[1]);
        }
        else if(i+1 == N) {
            ans = max(ans,l[i-1]);
        }
        else {
            ans = max(ans,__gcd(r[i+1],l[i-1]));
        }
    }
    cout << ans << endl;
}
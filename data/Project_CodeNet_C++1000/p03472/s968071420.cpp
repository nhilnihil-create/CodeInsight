#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,H;
    cin >> N >> H;
    vector<int>a(N);
    vector<int>b(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    int MAX = a[N-1];
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(b[i] >= MAX) {
            ans++;
            H-=b[i];
        }
        if(H <= 0) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans+(H+MAX-1)/MAX << endl;
}

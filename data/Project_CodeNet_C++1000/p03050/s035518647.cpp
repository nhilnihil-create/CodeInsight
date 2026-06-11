#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i*i+i < N; i++) {
        if((N-i)%i == 0) {
            ans+=(N-i)/i;
        }
    } 
    cout << ans << endl;
}

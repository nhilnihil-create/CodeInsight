#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N;
    vector<string>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int A[6];
    for(int i = 0; i < 5; i++) {
        A[i] = 0;
    }
    for(int i = 0; i < N; i++) {
        if(a[i][0] == 'M') {
            A[0]++;
        }
        if(a[i][0] == 'A') {
            A[1]++;
        }
        if(a[i][0] == 'R') {
            A[2]++;
        }
        if(a[i][0] == 'C') {
            A[3]++;
        }
        if(a[i][0] == 'H') {
            A[4]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 5; j++) {
            for(int k = j+1; k < 5; k++) {
               ans+=A[i]*A[j]*A[k];
            }
        }
    }
    cout << ans << endl;
}
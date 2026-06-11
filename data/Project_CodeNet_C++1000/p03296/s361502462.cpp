#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (A[i]==A[i-1]) {
            A[i] = -1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
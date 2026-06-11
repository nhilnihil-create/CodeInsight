#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    
    int N;
    cin >> N;
    vector<int> A(N+2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    vector<int> D(N+1, 0);
    int sum = 0;
    for (int i = 0; i < N+1; i++) {
        D[i] = abs(A[i+1] - A[i]);
        sum += D[i];
    }
    
    for (int i = 1; i <= N; i++) {
        int ans = sum;
        ans -= (D[i-1] + D[i]);
        ans += abs(A[i+1] - A[i-1]);
        cout << ans << endl;
    }
    
}
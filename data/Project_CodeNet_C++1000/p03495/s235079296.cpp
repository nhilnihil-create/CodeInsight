#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N+1, 0);
    for (int i = 1; i <= N; i++){
        int a;
        cin >> a;
        A[a]++;
    }
    sort(A.begin(), A.end());
    
    int ans = 0;
    for (int i = 1; i <= N-K; i++) {
        ans += A[i];
    }
    cout << ans << endl;
}
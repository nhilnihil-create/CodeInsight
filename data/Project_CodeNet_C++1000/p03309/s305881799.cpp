#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i], B[i] = A[i] - i;
    
    //メディアンを
    sort(B.begin(),B.end());
    long long x = B[N/2];
    
    //答えを求める
    long long res = 0;
    for(int i = 0; i < N; i++){
        res += max(x - B[i], -x + B[i]);
    }
    cout << res << endl;
} 
 
#include <bits/stdc++.h>
using namespace std;

int N, K;
int main(){
    cin >> N >> K;
    
    vector<long long> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    
    long long res = 1LL<<60;
    
    for (int i = 0; i +K -1 < N; i++){
        long long left = x[i];
        long long right = x[i+K-1];
        
        long long firstMove = min(abs(left),abs(right));
        
        res = min(res, firstMove + right - left);
    }
    cout << res << endl;
}
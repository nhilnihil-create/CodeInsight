#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){
    long long N,K;
    cin >> N >> K;
    
    if(K == 0){
        cout << N * N << endl;
        return 0;
    }
    
    long long ans = 0;
    for(long long b = 1; b <= N; b++){
        long long d = N / b;
        ans += d * max(b - K, 0LL);
        if(N % b > 0){
            ans += max(0LL, N%b - K + 1);
        }
    }
    cout << ans << endl;
}


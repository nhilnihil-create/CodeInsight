#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long N, K;
    cin >> N >> K;
    long ans = 0;
    for(int b=K + 1; b <= N; b++){
        ans += (b - K) * ((N + 1) / b) + max(0l, (N + 1) % b - K);
        if(K == 0) ans--;
    }    
    cout << ans << endl;
    return 0;
}
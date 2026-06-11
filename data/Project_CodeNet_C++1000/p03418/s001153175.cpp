#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long int N, K;
    cin >> N >> K;
    long long int ans=0;
    for(long long int n=1; n<=N; n++) {
        // cout << max(n-K, (long long int)0)*(N/n)+max(N%n-K+1, (long long int)0) << endl;
        ans += max(n-K, (long long int)0)*(N/n)+max(N%n-K+1, (long long int)0);
        if(K==0) {
            ans--;
        }
    }
    cout << ans << endl;

    return 0;
    
}
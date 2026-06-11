#include <iostream>

using namespace std;

int main() {
    long long int N, K;
    cin >> N >> K;
    
    long long int ans;
    if(K==1) {
        ans = N*N*N;
    } else if(K%2==0) {
        ans = N/K;
        if(N%K>=K/2) ans++;
        ans *= ans*ans;
        ans += (N/K)*(N/K)*(N/K);
    } else {
        ans = (N/K)*(N/K)*(N/K);
    }
    cout << ans << endl;
    

    return 0;
    
}
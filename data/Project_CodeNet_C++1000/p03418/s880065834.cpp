#include <iostream>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;

    long ans = 0;
    for(int b=1; b<=N; b++){
        int d1 = (N/b)*max(b-K, 0);
        int d2 = max(N%b-K+1, 0);
        ans += d1 + d2;
        if(K == 0)ans--;
    }

    cout << ans << endl;

    return 0;
}

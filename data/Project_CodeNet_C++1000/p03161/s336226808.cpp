#include <iostream>
using namespace std;
const int maxn = 1e5;
int h[maxn];
int dp[maxn];
int N, K;

int main(int argc, char const *argv[])
{
    cin >> N >> K;
    for(int i = 0 ; i<N ; i++){
        cin >> h[i];
    }
    dp[0] = 0;
    for(int i = 1 ; i<N ; i++){
        int minx = 0x3f3f3f3f;
        for(int j = 1 ; j<=K ; j++){
            if(i - j < 0) continue;
            minx = min(minx, dp[i - j] + abs(h[i-j] - h[i]));
        }
        dp[i] = minx;
    }
    cout << dp[N-1] << endl;
}
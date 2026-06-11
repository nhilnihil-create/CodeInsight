#include <iostream>
using namespace std;
const int maxn = 1e5;
int h[maxn];
int dp[maxn];
int N;

int main(int argc, char const *argv[])
{
    cin >> N;
    for(int i = 0 ; i<N ; i++){
        cin >> h[i];
    }
    dp[0] = 0;
    dp[1] = dp[0] + abs(h[0] - h[1]);
    for(int i = 2 ; i<N ; i++){
        int t1 = dp[i-2] + abs(h[i-2] - h[i]);
        int t2 = dp[i-1] + abs(h[i-1] - h[i]);
        dp[i] = min(t1, t2);
    }
    cout << dp[N-1] << endl;
}
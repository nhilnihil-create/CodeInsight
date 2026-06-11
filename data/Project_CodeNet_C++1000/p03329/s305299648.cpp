#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

#define MOD 1000000007



int N;

long long h[100010];

long long dp[100010];

int main(){

    int N; cin >> N;

    for(int i = 0; i < 100010; ++i) dp[i] = INF;

    dp[0] = 0;

    for(int i = 0; i < N; i++){
        
        chmin(dp[i+1], dp[i] + 1);

        int n6 = 1;
        int n6_num = pow(6, n6);

        while((i + n6_num) <= N){
            chmin(dp[i+n6_num], dp[i]+1);
            n6+=1;
            n6_num = pow(6, n6);
        }

        int n9 = 1;
        int n9_num = pow(9, n9);

        while((i + n9_num) <= N){
            chmin(dp[i+n9_num], dp[i]+1);
            n9+=1;
            n9_num = pow(9, n9);
        }
    }

    cout << dp[N] << endl;

}
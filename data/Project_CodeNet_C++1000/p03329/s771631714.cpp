#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long
#define assign_max(into, compared) (into = max((into), (compared))) 
#define assign_min(into, compared) (into = min((into), (compared))) 

using namespace std;

int main(void){
    int N;
    cin >> N;

    vector<int> dp (N+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0;i < N;i++){
        assign_min(dp[i+1], dp[i]+1);
        for(int j = 6;i+j <= N;j *= 6){
            assign_min(dp[i+j], dp[i]+1);
        }

        for(int j = 9;i+j <= N;j *= 9){
            assign_min(dp[i+j], dp[i]+1);
        }
    }
    cout << dp[N] << endl;
}
#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;

ll dp[1010000];

int main(){
    int N;  cin >> N;
    string s;   cin >> s;
    int Q, K[75];
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> K[i];
    }

    int numD[1010000], numM[1010000];
    numD[0] = 0; numM[0] = 0;
    for(int i = 0; i < N; i++){
        numM[i+1] = numM[i] + (s[i] == 'M');
        numD[i+1] = numD[i] + (s[i] == 'D');
    }

    for(int ki = 0; ki < Q; ki++){
        int k = K[ki];
        ll res = 0;
        dp[0] = 0;
        for(int i = 1; i <= N; i++){
            dp[i] = dp[i-1];
            if(s[i-1] == 'C'){
                res += dp[i];
            }
            if(s[i-1] == 'M'){
                dp[i] += numD[i] - numD[max(0, i-k+1)];
            }
            if(i - k >= 0 && s[i-k] == 'D'){
                dp[i] -= numM[i-1] - numM[i-k+1];
            }
        }
        cout << res << endl;
    }


    return 0;
}
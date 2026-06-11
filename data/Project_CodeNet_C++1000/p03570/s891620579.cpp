#include <bits/stdc++.h>

//#define li long int
#define INF 100000000
#define POW26 67108864

using namespace std;

int main() {
    vector < int > a(200001, 0), opt(200001, INF), dp(POW26, INF);
    int len;
    char c;

    //for (int i=0; i<POW26; i++) dp[i] = INF;
    //for (int i=0; i<200001; i++) opt[i] = INF;
    
    for (len=0; (c = getchar()) != '\n'; len++) {
        a[len+1] = a[len] ^ (1 << (c - 'a'));
        //cout << a[len] << endl;
    }
    
    opt[0] = 0;
    for (int i=1; i<=len; i++) {
        dp[a[i-1]] = min(dp[a[i-1]], opt[i-1]);

        opt[i] = dp[a[i]^0];
        for (int x = 1; x < POW26; x <<= 1) {
            opt[i] = min(opt[i], dp[a[i]^x]);
            //cout << (li)(a[i]^x) << ", " << dp[a[i]^x] << endl;
            //cout << i << ", " << dp[a[i]^x] << endl;
        }
        opt[i]++;
    }

    cout << opt[len] << endl;

    return 0;
}
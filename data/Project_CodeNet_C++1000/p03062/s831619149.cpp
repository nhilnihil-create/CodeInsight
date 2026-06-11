#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

#define INF  -10000000000

int main()
{
    long long dp[100005][2];
    long long a[100005];
    int n;
    
    cin >> n;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    dp[0][0] = a[0]+a[1];
    dp[0][1] = -a[0]-a[1];
    
    for (int i = 0;i < n-2;i++){
        dp[i+1][0] = max(dp[i][0]+a[i+2],dp[i][1]+a[i+2]);
        dp[i+1][1] = max(dp[i][0]-2*a[i+1]-a[i+2],dp[i][1]+2*a[i+1]-a[i+2]);
    }
    cout << max(dp[n-2][0],dp[n-2][1]) << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
//#define int long long
using namespace std;
const int K = 1<<26;
int INF = 1e9;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int XOR = 0;
    vector<int> dp(K);
    fill(dp.begin(), dp.end(), INF);
    dp[0] = 0;
    int answer = INF;
    for (int i=0; i < s.size(); i++){
        answer = INF;
        XOR ^= 1 << (s[i] - 'a');
        answer = min(answer, dp[XOR] + 1);
        for (int j=0; j < 26; j++){
            answer = min(answer, dp[XOR ^ (1 << j)] + 1);
        }
        dp[XOR] = min(dp[XOR], answer);
    }
    cout << answer << endl;
    return 0;
}


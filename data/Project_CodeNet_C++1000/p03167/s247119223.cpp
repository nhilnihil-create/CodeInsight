#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdio>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;

int N, M;
char arr[1100][1100];
int dp[1100][1100];

const int MOD = 1e9+7;

int main(){
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if (arr[i][j] == '#') continue;
            dp[i][j] += dp[i-1][j];
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    printf("%d", dp[N][M]);
}

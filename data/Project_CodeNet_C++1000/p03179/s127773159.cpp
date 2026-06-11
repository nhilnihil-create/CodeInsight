#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 3005;

int n;
int sum[maxn], dp[maxn][maxn];
char s[maxn];

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	dp[0][0] = sum[0] = 1;
	
	FOR(i, 1, n){
		REP(j, 0, i){
			if(s[i - 1] == '>') dp[i][j] = (sum[i - 1] - (j ? sum[j - 1] : 0) + INF) % INF;
			else if(j) dp[i][j] = sum[j - 1];
		}
		sum[0] = dp[i][0];
		REP(j, 1, i) sum[j] = (sum[j - 1] + dp[i][j]) % INF;
	}
	
	printf("%d\n", sum[n - 1]);
	return 0;
}
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define REP1(i,b,a) for(i=b-1;i>=a;i--)
#define output(x) cout<<x<<endl;
#define pb(x) push_back(x);
typedef long long int ll;
const int MAX = 510000;
const int MOD = 1000000007;

int main()
{

	ll i, j, k, l, m, flag, N, M, K, H, W, X, P, A, B, C;
	char S[100001];
	cin >> S;
	int num[3] = {};
	REP(i, 0, strlen(S)) {
		if (S[i] == 'a') {
			num[0]++;
		}
		if (S[i] == 'b') {
			num[1]++;
		}
		if (S[i] == 'c') {
			num[2]++;
		}
	}
	k = strlen(S);
	if (k % 3 == 0) {
		REP(i, 0, 3) {
			if (num[i] != k / 3) {
				output("NO");
				return 0;
			}
		}
	}
	else{
		REP(i, 0, 3) {
			if (num[i] < k / 3||num[i]>k/3+1) {
				output("NO");
				return 0;
			}
		}
	}

	output("YES");
	return 0;
}




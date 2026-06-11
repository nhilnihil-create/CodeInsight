#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9+7, MAX = 1e9, larg = 1e5, INF = -1e9;
int A,B,C,D,E,F,G,H,I,J,K,L,N,M,O,P,Q,R,S,T,U,V,W,X,Y,Z;
int max_value = 0, max_index = 0;
int min_value = MAX, min_index = 0;

typedef pair<int, int> Po;
typedef long long ll;

int dp[10001];

int main() {
	cin >> N >> M;
	int a[9] = {2,5,5,4,5,6,3,7,6}, num;
	vector<int> canuse;
	vector<int> many;
	bool flag = false;
	rep(i, M){
		cin >> num;
		canuse.push_back(num);
		if(a[num-1] == 5 && flag) continue;
		if(a[num-1] == 5) flag = true;
		many.push_back(a[num-1]);
	}
	sort(many.begin(), many.end());

	dp[0] = 0;
	rep(i, N){
		dp[i+1] = INF;
		rep(j, many.size()){
			if(i+1-many[j] > -1) dp[i+1] = max(dp[i+1], dp[i+1-many[j]]+1);
		}
	}

	sort(canuse.begin(), canuse.end(), greater<int>());

	int curr = N;
	while(curr != 0){
		rep(i, canuse.size()){
			if(curr-a[canuse[i]-1] < 0) continue;
			if(dp[curr-a[canuse[i]-1]] == dp[curr]-1){
				cout << canuse[i];
				curr -= a[canuse[i]-1];
				break;
			}
		}
	}
}
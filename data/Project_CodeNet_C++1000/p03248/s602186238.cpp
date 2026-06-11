#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define VI vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e5;
char S[MAXN+10];
int n;
int main(){
	scanf("%s", S);
	n = strlen(S);
	if(S[0] == '0' || S[n-1] == '1'){
		printf("-1\n");
		return 0;
	}
	for(int i = 0; i < (n-1)/2; i++){
		if(S[i] != S[n-i-2]){
			printf("-1\n");
			return 0;
		}
	}
	int cur = 1, nxt = 2;
	for(int i = 0; i < n - 1; i++){
		printf("%d %d\n", cur, nxt);
		if(S[i] == '1') cur = nxt; 
		nxt++;
	}
	return 0;
}
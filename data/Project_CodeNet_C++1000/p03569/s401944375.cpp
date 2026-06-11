#include <bits/stdc++.h>
using namespace std;

const int maxN = 100010;

int A[maxN];
char S[maxN], ox[maxN];

int main (){
	int i, j, c;
	scanf("%s", S);
	for(i = j = c = 0; S[i]; ++i){
		if(S[i] == 'x') ++c;
		else{
			ox[j] = S[i];
			A[j++] = c;
			c = 0;
		}
	}
	A[j] = c;
	for(i = 0; i < j; ++i) if(ox[i] != ox[j - 1 - i]) break;
	if(i == j){
		int ans = 0;
		for(i = 0; i <= j; ++i) ans += abs(A[i] - A[j - i]);
		printf("%d\n", ans / 2);
	}
	else puts("-1");
	return 0;
}

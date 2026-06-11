// D - Wide Flip
#include <bits/stdc++.h>
using namespace std;

int main(){
	char S[100000+1]; scanf("%s",S);
	int K = strlen(S);
	for(int N=K, i=1; i<N; ++i)
		if(S[i-1] != S[i]) K = min(K, max(i, N-i));
	printf("%d\n",K);
}
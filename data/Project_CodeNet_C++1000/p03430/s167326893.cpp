#include <cstdio>
#include <cstring>
#include <memory.h>

char S[310];
int K;
int len;
int res;
int memo[310][310][310];

int srch(int ll, int rr, int kk)
{
	if(memo[ll][rr][kk] != -1)
		return memo[ll][rr][kk];
	if(ll==rr)
		return 1;
	if(ll+1==rr){
		if(S[ll]==S[rr] || kk>0)
			return 2;
		else
			return 1;
	}
	int tmp;
	int mx=0;
	tmp = srch(ll+1, rr, kk);
	if(tmp > mx)
		mx = tmp;
	tmp = srch(ll, rr-1, kk);
	if(tmp > mx)
		mx = tmp;
	if(S[ll]==S[rr]){
		tmp = srch(ll+1, rr-1, kk) + 2;
		if(tmp > mx)
			mx = tmp;
	}
	else if(kk>0){
		tmp = srch(ll+1, rr-1, kk-1) + 2; 
		if(tmp > mx)
			mx = tmp;
	}
	memo[ll][rr][kk] = mx;
	return mx;
}

void solve()
{
	len = strlen(S);
	memset(memo, -1, sizeof(memo) );
	res = srch(0, len-1, K);
	printf("%d\n", res);
}

int main()
{
	scanf("%s", S);
	scanf("%d", &K);
	solve();
	return 0;
}
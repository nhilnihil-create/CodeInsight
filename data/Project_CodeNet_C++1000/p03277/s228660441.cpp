#include <stdio.h>

int N,A[100100],B[200200];

void push(int x)
{
	while (x <= N * 2 + 2){
		B[x]++;
		x += x & (-x);
	}
}

int pop(int x)
{
	int r = 0;
	while (x){
		r += B[x];
		x -= x & (-x);
	}
	return r;
}

bool chk(int x)
{
	long long need = ((long long)N * (N + 1) / 2 + 1) / 2;
	long long cnt = 0;

	for (int i=0;i<=N*2+2;i++) B[i] = 0;
	int bal = N+1;
	for (int i=1;i<=N;i++){
		push(bal);
		if (A[i] >= x) bal++;
		else bal--;
		cnt += pop(bal);
	}

	return cnt >= need;
}

int main()
{
	scanf ("%d",&N);
	for (int i=1;i<=N;i++) scanf ("%d",&A[i]);

	int l = 0, r = 1000000001;
	while (l + 1 < r){
		int m = (l + r) / 2;
		if (chk(m)) l = m;
		else r = m;
	}

	printf ("%d\n",l);

	return 0;
}
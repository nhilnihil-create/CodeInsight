#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int Q;
int A, B;
long long res;

long long sqrtll(long long x)
{
	long long l=1, r=2000000000;
	long long m;
	while(l<r){
		m = (l+r)/2;
		if(m*m >= x)
			r = m;
		else
			l = m+1;
	}
	if (l*l>x)
		l --;
	return l;
}

void solve()
{
	res = 0;
	if(A>B)
		swap(A, B);
	res += (A-1)*2;
	long long sq = int(sqrt(1.0*A*B)+1E-8);
	if(sq*(sq+1)<1ll*A*B)
		res ++;
	if(sq*sq<1ll*A*B)
		res ++;
	if(sq-A>=0)
		res += (sq-A)*2;
	if(A!=B)
		res --;
	printf("%lld\n", res);
}

int res2;
int vis[1000000];
void solve2()
{
	int i;
	for(i=0; i<1000000; i++)
		vis[i] = 0;
	res2 = 0;
	for(i=1; i<A; i++){
		int tmp = A*B/i;
		if(tmp*i<A*B){
			if(vis[tmp]==0){
				vis[tmp] = 1;
				res2 ++;
			}
		}
	}
	for(i=0; i<1000000; i++)
		vis[i] = 0;
	for(i=1; i<B; i++){
		if(vis[i]==1)
			continue;
		int tmp = (A*B)/i;
		if(tmp*i < A*B && vis[tmp]==0){
			if(tmp > A){
				res2 ++;
			}
		}
		else{
			tmp --;
			while(vis[tmp]==1){
				tmp --;
				if(tmp == 0)
					break;
			}
			if(tmp>A)
				res2 ++;
		}
	}
	printf("%d\n", res2);
}

void test1()
{
	A = rand()%5+1;
	B = rand()%5+1;
	solve();
	solve2();
	if(res != res2){
		printf("Wrong\n");
		solve();
	}
}

void test()
{
	int i;
	for(i=0; i<100; i++)
		test1();
}

int main()
{
	//test();
	int i;
	scanf("%d", &Q);
	for(i=0; i<Q; i++){
		scanf("%d%d", &A, &B);
		solve();
		//solve2();
	}
	return 0;
}
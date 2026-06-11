#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

int S(long long c)
{
	int ret=0;
	while(c) ret+=c%10, c/=10;
	return ret;
}

void get_next(long long &c)
{
	for(long long i=1;;i*=10) {
		if(c/i%10==9) continue;
		int diff=9-c/i%10;
		long long n=c+diff*i;
		if(c*S(n)<=n*S(c)) return;
		c=n;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int K;
	long long c=1;
	for(cin>>K;K;K--) {
		cout<<c++<<'\n';
		get_next(c);
	}
	return 0;
}
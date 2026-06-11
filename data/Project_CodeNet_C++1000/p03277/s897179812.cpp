#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<int> A;
int tree[222222];

void update(int n, int v)
{
	for(;n<222222;n+=n&-n) tree[n]+=v;
}

int get_cnt(int n)
{
	int ret=0;
	for(;n;n-=n&-n) ret+=tree[n];
	return ret;
}

long long cnt_pair(int l)
{
	long long ret=0;
	int c=A.size()+1;
	memset(tree,0,sizeof(tree));
	update(c,1);
	for(auto a: A) {
		ret+=get_cnt(c+=(a>=l ? 1:-1));
		update(c,1);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, s=1, e=1e9;
	long long K;
	cin>>N;
	K=(1LL*N*(N+1)/2+1)/2;
	A.resize(N);
	for(int i=0;i<N;i++) cin>>A[i];
	while(s<=e) {
		int m=(s+e)>>1;
		if(cnt_pair(m)>=K) s=m+1;
		else e=m-1;
	}
	cout<<e<<'\n';
	return 0;
}
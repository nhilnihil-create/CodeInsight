#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

long long x[100001], V[100001], VM[100001], VM2[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N;
	long long C, ans;
	cin>>N>>C;
	for(int i=1;i<=N;i++) {
		cin>>x[i]>>V[i];
		V[i]+=V[i-1];
		VM[i]=max(VM[i-1],V[i]-x[i]);
		VM2[i]=max(VM2[i-1],V[i]-2*x[i]);
	}
	ans=VM[N];
	for(int i=N;i>0;i--) {
		ans=max(ans,V[N]-V[i-1]+max(VM[i-1]-2*(C-x[i]),VM2[i-1]-(C-x[i])));
	}
	cout<<ans<<'\n';
	return 0;
}
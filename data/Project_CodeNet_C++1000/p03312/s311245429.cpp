#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

long long PS[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N;
	long long ans=0x7fffffffffffffffLL;
	cin>>N;
	for(int i=1;i<=N;i++) cin>>PS[i], PS[i]+=PS[i-1];
	for(int i=N-2;i>1;i--) {
		vector<long long> V;
		int s=1, e=i-1;
		while(s<=e) {
			int m=(s+e)>>1;
			if(abs(PS[i]-2*PS[m])<abs(PS[i]-2*PS[m+1])) e=m-1;
			else s=m+1;
		}
		V.push_back(PS[s]);
		V.push_back(PS[i]-PS[s]);
		s=i+1, e=N-1;
		while(s<=e) {
			int m=(s+e)>>1;
			if(abs(PS[N]+PS[i]-2*PS[m])<abs(PS[N]+PS[i]-2*PS[m+1])) e=m-1;
			else s=m+1;
		}
		V.push_back(PS[s]-PS[i]);
		V.push_back(PS[N]-PS[s]);
		sort(V.begin(),V.end());
		ans=min(ans,V[3]-V[0]);
	}
	cout<<ans<<'\n';
	return 0;
}
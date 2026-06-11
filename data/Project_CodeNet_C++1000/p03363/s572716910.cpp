#include "bits/stdc++.h"
using namespace std;
const int maxN=2e5+10;
int N;
long long A[maxN],presum[maxN],ans=0LL;
map<long long,long long> cnt;
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=N;i++) presum[i]=presum[i-1]+A[i];
	for(int i=1;i<=N;i++) cnt[presum[i]]++;
	for(int i=N;i>=1;i--)
	{
		ans+=cnt[presum[i]]-1LL;
		if(presum[i]==0LL) ans++;
		cnt[presum[i]]--;
	}
	cout<<ans<<endl;
	return 0;
}
/*
6
1 3 -4 2 2 -2
Output:3

7
1 -1 1 -1 1 -1 1
Output:12

5
1 -2 3 -4 5
Output:0

3
0 0 0
Output:6

5
1 -1 2 -2 3
Output:3
*/
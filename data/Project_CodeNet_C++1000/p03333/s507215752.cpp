#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;

priority_queue <int> q1,q2;
int sign[N],L[N],R[N],n,Ans,sum;
signed main()
{
	q1.push(0); q2.push(0);
	cin >> n; for(int i=1;i<=n;i++)
		cin >> L[i] >> R[i];
	for(int i=1;i<=n;i++) q1.push(-R[i]);
	for(int i=1;i<=n;i++) q2.push(L[i]);
	for(int i=0;i<=n/2;i++)
		sum+=2*(q2.top()+q1.top()),
		q1.pop(), q2.pop(),
		Ans=max(Ans,sum);
	cout << Ans << endl;
}
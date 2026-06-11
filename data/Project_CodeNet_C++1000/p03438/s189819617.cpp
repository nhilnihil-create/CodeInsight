#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	int as=0,bs=0;
	for(int &i:a)cin>>i,as+=i;
	for(int &i:b)cin>>i,bs+=i;

	int k=bs-as;int tmp=0;
	for(int i=0;i<n;i++)
		if(a[i]<b[i])tmp+=(b[i]-a[i]+1)/2;
	if(tmp<=k)puts("Yes");
	else puts("No");

}

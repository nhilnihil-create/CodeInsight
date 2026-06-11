#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;

const int MOD=1000000007;

int a[100010],b[100010];
int main()
{
	int n,h;
	int ans=0;
	cin>>n>>h;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	
	int po=lower_bound(b,b+n,a[n-1]+1)-b;
	int i=n-1;
	while(h>0 && i>=po)
	{
		h-=b[i];
		ans++;
		i--;
	}
	
	if(h>0)ans+=(h-1)/a[n-1]+1;
	cout<<ans<<"\n";
	return 0;
}
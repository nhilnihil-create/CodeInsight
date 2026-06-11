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
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;

LL gcd(LL a,LL b)
{
	if(a<b)return gcd(b,a);
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	LL n,x;cin>>n>>x;
	LL a[100010];
	for(LL i=0;i<n;i++)cin>>a[i];
	LL ans=0;
	for(LL i=0;i<n;i++)
	{
		if(i==0)ans=abs(a[0]-x);
		else ans=gcd(ans,abs(a[i]-x));
	}
	cout<<ans<<"\n";
	return 0;
}
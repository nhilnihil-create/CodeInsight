#include<map>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int n;
long long ans;
char str[10005];
map<pair<string,string>,int>f;

int main()
{
	scanf("%d%s",&n,str);
	int mxs = 1<<n;
	for(int s = 0; s < mxs; s++)
	{
		string a,b;
		for(int j = 0; j < n; j++)
		{
			if((s>>j)&1) a += str[j];
			else b += str[j];
		}
		f[make_pair(a,b)]++;
	}
	for(int s = 0; s < mxs; s++)
	{
		string a,b;
		for(int j = 0; j < n; j++)
		{
			if((s>>j)&1) a += str[(n<<1)-1-j];
			else b += str[(n<<1)-1-j];
		}
		ans+=f[make_pair(a,b)];
	}
	printf("%lld",ans);
	return 0;
}
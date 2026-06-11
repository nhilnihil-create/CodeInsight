#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char c[1000000];
int num[100];
int main()
{	scanf("%s",c+1);
	int n=strlen(c+1),tag=1,le=0,ri;
	for(rint i=1;i<=n;i++) num[c[i]-'a']++;
	sort(num,num+26,greater<int>());
	for(rint i=25;;i--) if(num[i]){ri=i;break;}
	while(le<ri-1)
	{	if(num[le]-1>num[ri])
		{	num[le]-=num[ri];
			num[ri-1]-=num[ri];
			ri--;
		}
		else
		{	num[ri]-=num[le]-1;
			num[ri-1]-=num[le]-1;
			num[le]=0;
			le++;
		}
	}
	for(rint i=0;i<26;i++) if(num[i]!=0&&num[i]!=1) tag=0;
	if(!tag) cout<<"NO\n";
	else cout<<"YES\n";
 	return 0;
}

#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

template <class T>
void read(T &x)
{
	char ch;
	for (ch=getchar();(ch<'0'||ch>'9')&&ch!='-';) ch=getchar();
	x=0;int t=1;if (ch=='-') {ch=getchar();t=-1;}
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x*=t;
}

char a[200010];
int b[1<<26];

int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
	scanf("%s",a+1);int n=strlen(a+1);
	int m=(1<<26);
	for (int i=1;i<m;i++) b[i]=n;b[0]=0;
	int t=0;
	for (int i=1;i<=n;i++)
	{
		t^=(1<<(a[i]-97));
		for (int j=0;j<26;j++) b[t]=min(b[t],b[t^(1<<j)]+1);
	}
	printf("%d\n",max(b[t],1));
	return 0;
}


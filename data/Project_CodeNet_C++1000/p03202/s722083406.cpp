#include<bits/stdc++.h>
#define llong long long
#define pii pair<int,int>
#define mkpr make_pair
#define riterator reverse_iterator
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int N = 2e5;
int len[N+3];
set<pii> a;
int n;

bool check(int s)
{
//	printf("check %d\n",s);
	a.clear();
	for(int i=1; i<=n; i++)
	{
		if(len[i]<=len[i-1])
		{
			set<pii>::riterator iter=a.rbegin();
			while(iter!=a.rend() && (*iter).first>len[i]) {a.erase((++iter).base()); iter = a.rbegin();}
			int tmp = len[i];
			while(iter!=a.rend()&&(*iter).first==tmp&&(*iter).second==s-1)
			{
				a.erase((++iter).base()); tmp--; iter = a.rbegin();
			}
			if(tmp==0) {return false;}
			int x = 1;
			if(iter!=a.rend()&&(*iter).first==tmp) {x = (*iter).second+1; a.erase((++iter).base()); iter = a.rbegin();}
			a.insert(mkpr(tmp,x));
//			printf("i=%d ",i); for(set<pii>::iterator iter=a.begin(); iter!=a.end(); iter++) printf("(%d,%d) ",(*iter).first,(*iter).second); puts("");
		}
	}
	return true;
}

int main()
{
	scanf("%d",&n); bool f = true;
	for(int i=1; i<=n; i++) {scanf("%d",&len[i]); if(len[i]<=len[i-1]) {f = false;}}
	if(f) {puts("1"); return 0;}
	int left = 2,right = n;
	while(left<right)
	{
		int mid = left+(right-left>>1);
		bool ok = check(mid);
		if(ok) right = mid;
		else left = mid+1;
	}
	printf("%d\n",right);
	return 0;
}
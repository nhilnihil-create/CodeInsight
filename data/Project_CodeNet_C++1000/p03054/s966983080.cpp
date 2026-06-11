#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[8];
int h,w,n,sx,sy;
char s[200005],t[200005];
int main()
{
	scanf("%d%d%d%d%d",&h,&w,&n,&sx,&sy);
	scanf("%s",&s);
	scanf("%s",&t);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
		cnt[0]++;
		if(s[i]=='R')
		cnt[1]++;
		if(s[i]=='U')
		cnt[2]++;
		if(s[i]=='D')
		cnt[3]++;
		if(sy-cnt[0]+cnt[5]<=0)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(sy+cnt[1]-cnt[4]>w)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(sx-cnt[2]+cnt[7]<=0)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(sx+cnt[3]-cnt[6]>h)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(t[i]=='L'&&sy-cnt[4]+cnt[1]-1>0)
		cnt[4]++;
		if(t[i]=='R'&&sy+cnt[5]+1-cnt[0]<=w)
		cnt[5]++;
		if(t[i]=='U'&&sx-cnt[6]-1+cnt[3]>0)
		cnt[6]++;
		if(t[i]=='D'&&sx+cnt[7]+1-cnt[2]<=h)
		cnt[7]++;
	}
	cout << "YES" << endl;
    return 0;
}
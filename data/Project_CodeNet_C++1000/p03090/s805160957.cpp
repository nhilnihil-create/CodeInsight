#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> a1,a2;

int main()
{
	int n; cin>>n;
	if(n==3) printf("2\n1 3\n2 3\n");
	else
	{
		if(n%2==0)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(i+j!=n+1) a1.pb(i),a2.pb(j);
				}
			}
		}
		else
		{
			n--;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(i+j!=n+1) a1.pb(i),a2.pb(j);
				}
			}
			rep(i,1,n) a1.pb(i),a2.pb(n+1);
		}
		cout<<a1.size()<<endl;
		rep(i,0,(int)a1.size()-1) printf("%d %d\n",a1[i],a2[i]);
	}
	return 0;
}
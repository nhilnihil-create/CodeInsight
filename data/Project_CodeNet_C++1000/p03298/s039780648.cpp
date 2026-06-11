#include<bits/stdc++.h>

using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

const int maxn = (1<<20)+20;

struct Node{
	string blue,red;
};

Node f[maxn];
map<pair<string,string>,int> mp;
int n,m;
char s[1010];
char s1[1010];
int cnt;

int main()
{
    n=read();
    scanf("%s",s+1);
    for (int i=n+1;i<=2*n;i++) s1[i-n]=s[i];
    
    for (int i=0;i<(1<<n);i++)
    {
         string sb,sr;
         sb.clear();
         sr.clear();
         for (int j=1;j<=n;j++) if (i&(1<<(j-1))) sb=s[j]+sb; else sr+=s[j];
         f[++cnt].blue=sb;
         f[cnt].red=sr;
    }

    for (int i=0;i<(1<<n);i++)
    {
    	string sb,sr;
    	sb.clear();
    	sr.clear();
    	for (int j=1;j<=n;j++) if (i&(1<<(j-1))) sb=s1[j]+sb; else sr=sr+s1[j];
    	mp[make_pair(sb,sr)]++;
    }
    long long ans=0;
    for (int i=1;i<=cnt;i++)
    {
         if (mp[make_pair(f[i].red,f[i].blue)]) ans+=mp[make_pair(f[i].red,f[i].blue)]; 
    } 
    cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<int,int>
#define vint vector<int>
#define pb push_back
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
int read(){
	int g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const int N=30;
char s[N];
int n,vis[N];
namespace solve1{
	void Main(){
		for(int i=1;i<=n;i++)cout<<s[i],vis[s[i]-'a']=1;
		for(int i=0;i<26;i++)if(!vis[i]){cout<<(char)(i+'a');break;}
	}
}
namespace solve2{
	void Main(){
		vis[s[n]-'a']=1;	
		for(int i=n-1;i>=1;i--){
			for(int j=s[i]-'a'+1;j<26;j++)if(vis[j]){
				s[i]=(char)(j+'a');
				for(int k=1;k<=i;k++)cout<<s[k];
				return void();
			}vis[s[i]-'a']=1;
		}puts("-1");
	}
}
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	if(n<26)solve1::Main();
	else solve2::Main();
	return signed();
}
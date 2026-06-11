#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 2e5;
const int inf = 1e6;
map<int ,int> mp;
char s[maxn+10];
int f[maxn+10];
int main() {
	//freopen("in","r",stdin);
	scanf("%s",s);
	int n=strlen(s);
	mp[0]=0;
	int state=0;
	for(int i=0;i<n;i++) {
		state^=1<<(s[i]-'a');
		f[i]=inf;
		for(int j=0;j<26;j++)
			if(mp.find(state^(1<<j))!=mp.end()) f[i]=min(f[i],mp[state^(1<<j)]+1);
		if(mp.find(state)!=mp.end()) f[i]=min(f[i],mp[state]+1);
		if(mp.find(state)==mp.end()) mp[state]=f[i];
		else if(mp[state]>f[i]) mp[state]=f[i];
	}
	printf("%d\n",f[n-1]);
	return 0;
}
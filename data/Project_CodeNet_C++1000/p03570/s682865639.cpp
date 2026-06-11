#include <cstdio>
#include <cstring>
#include <unordered_map>
#define ele int
using namespace std;
#define maxn 200010
ele n,tag,f[maxn];
char s[maxn];
unordered_map<ele,ele> mp;
int main(){
	scanf("%s",s); n=strlen(s);
	f[0]=0; tag=0;
	mp[0]=0;
	for (int i=1; i<=n; ++i){
		f[i]=1e9;
		tag^=1<<(s[i-1]-'a');
		for (int j=0; j<26; ++j){
			ele x=tag^(1<<j);
			if (mp.find(x)!=mp.end()) f[i]=min(f[i],mp[x]+1);
		}
		if (mp.find(tag)!=mp.end()){
			f[i]=min(f[i],mp[tag]+1);
			mp[tag]=min(mp[tag],f[i]);
		}
		else mp[tag]=f[i];
	}
	printf("%d\n",f[n]);
	return 0;
}
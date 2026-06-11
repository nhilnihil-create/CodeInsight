#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int cnt[4],n;
char s[N];
void dfs(int x,int last1,int last2){
	if (x>n){
		puts("YES");
		exit(0);
	}
	if (cnt[0]&&last1!=1&&last2!=1){
		cnt[0]--;
		dfs(x+1,last2,1);
		cnt[0]++;
	}
	if (cnt[1]&&last2!=2&&last1!=2){
		cnt[1]--;
		dfs(x+1,last2,2);
		cnt[1]++;
	}
	if (cnt[2]&&last2!=3&&last1!=3){
		cnt[2]--;
		dfs(x+1,last2,3);
		cnt[2]++;
	}
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;s[i];i++)cnt[s[i]-'a']++;
	dfs(1,0,0);
	puts("NO");
}
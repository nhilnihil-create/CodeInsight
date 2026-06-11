#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
map<int,int> M;
char s[N];
int main(){
	scanf("%s",s+1);
	int n = strlen(s+1);
	int tmp = 0;
	for(int i =1;i<=n;i++){
		tmp^=1<<(s[i]-'a');
	}
	//cout<<tmp<<endl;
	if(tmp==0){
		puts("1");
		return 0;
	}
	tmp = 0;
	M[0] = 0;
	int tmp2,cnt;
	for(int i =1;i<=n;i++){
		tmp^=1<<(s[i]-'a');
		tmp2 = 1e9;
		cnt = 0;
		for(int j = 0;j<26;j++) {
		
			if(M.count(tmp^(1<<j)))
				tmp2 = min(tmp2,M[tmp^(1<<j)]+1);
			if(tmp>>j&1) cnt++;
		}
		if(cnt==1) tmp2 = 1;
		if(M.count(tmp)) M[tmp] = min(M[tmp],tmp2);
		else M[tmp] = tmp2;
	}
	printf("%d\n",M[tmp]);
	return 0;
} 
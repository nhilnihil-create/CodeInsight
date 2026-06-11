#include<bits/stdc++.h>
using namespace std;
int k[15],s[15][15];
int p[15];
int n,m;
int ans;
int check(int x){
	for(int i=0;i<m;i++){
			int l=0;
		for(int j=0;j<k[i];j++){
			l^=((x>>s[i][j])&1);
		}
		if(l!=p[i])
			return 0;
	}
	return 1;
}
int main(){
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d",&s[i][j]);
			s[i][j]--;
		}
	}
	for(int i=0;i<m;i++)
		scanf("%d",&p[i]);
	ans=0;
	for(int i=0;i<(1<<n);i++){
		if(check(i))
			ans++;
	}
	cout<<ans<<"\n";
}
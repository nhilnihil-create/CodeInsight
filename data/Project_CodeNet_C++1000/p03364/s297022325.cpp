#include<bits/stdc++.h>
using namespace std;
const int N=310;
char s[N][N];
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
		scanf("%s",s[i]);
	for(int i=0; i<n; ++i){
		int flag=1;
		for(int j=0; j<n; ++j)
			for(int k=0; k<n; ++k)
				if(s[j][(i+k)%n]!=s[k][(i+j)%n])
					flag=0;
		ans+=flag*n;
	}
	printf("%d",ans);
	return 0;
}
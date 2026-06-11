#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=300+10;
int n,x,f[maxn][maxn][maxn],ans;
char s[maxn];

void chkmax(int&a,int b){if(a<b)a=b;}

int main(){
	cin>>(s+1)>>x;
	n=strlen(s+1);
	for(int i=0;i<=n;++i)
		for(int j=n+1;i<j;--j)
			for(int k=0;k<=x;++k){
				if(i+1<j)
					chkmax(ans,f[i][j][k]+1);
				else
					chkmax(ans,f[i][j][k]);
				if(i+1<j){
					chkmax(f[i+1][j][k],f[i][j][k]);
					chkmax(f[i][j-1][k],f[i][j][k]);
				}
				if(i+1<j-1)
					if(s[i+1]==s[j-1])
						chkmax(f[i+1][j-1][k],f[i][j][k]+2);
					else if(k<x)
						chkmax(f[i+1][j-1][k+1],f[i][j][k]+2);
			}
	cout<<ans<<endl;
	return 0;
}

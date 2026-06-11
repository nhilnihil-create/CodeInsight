#include<bits/stdc++.h>
using namespace std;
const int N = 300+5;
char s[N];
int f[N][N][N];
bool v[N][N][N];
inline int q(int l,int r,int k){
	if(r-l+1<=1)return r-l+1>=1;
	if(v[l][r][k])return f[l][r][k];
	v[l][r][k]=1;
	int diff = s[l]!=s[r];
	f[l][r][k]=max(q(l+1,r,k), q(l,r-1,k));
	if(k - diff>=0)f[l][r][k]=max(f[l][r][k],q(l+1,r-1,k-diff)+2);
	return f[l][r][k];
}

int main(){
	scanf("%s",s+1);
	int k;cin >> k;
	cout << q(1,strlen(s+1),k) << endl;
}

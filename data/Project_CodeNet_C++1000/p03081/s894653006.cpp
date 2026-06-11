#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
char s[N],si[N][2],di[N][2];

bool check(int mid,int k) {
	if (mid<1 || mid>n) return 1;
	for (int i=1;i<=m;i++) {
		if (s[mid]!=si[i][0]) continue;
		if (di[i][0]=='L') mid--; else mid++;
		if (k==1) if (mid<1) return 1;
		if (k==2) if (mid>n) return 1;
	}
	return 0;
}

int main()
{
	cin>>n>>m;
	scanf("%s",s+1);
	for (int i=1;i<=m;i++) scanf("%s%s",&si[i],&di[i]);
	
	int L=0,R=n,ans=0;
	while (L<R) {
		int mid=L+R+1>>1;
		if (check(mid,1)) L=mid; else R=mid-1;
	}
	ans+=L;
	
	L++; R=n+1;
	while (L<R) {
		int mid=L+R>>1;
		if (check(mid,2)) R=mid; else L=mid+1;
	} 
	ans+=(n-R+1);
	
	cout<<n-ans<<endl;
	return 0;
}
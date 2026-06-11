#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 233;
int n,a[maxn],b[maxn];
int sr,sc,x;
char s[maxn],t[maxn];
bool check(int l,int r,int maxi){
	for(int i=n;i;i--){
		if(b[i]==1)l--;
		if(b[i]==-1)r++;
		if(l<1)l = 1;
		if(r>maxi)r = maxi;
		if(a[i]==1)r--;
		if(a[i]==-1)l++;
		if(l>r)return 0;
	}
	if(l<=x&&x<=r)return 1;
	return 0;
}
int main()
{
	int h,w;cin>>h>>w>>n;
	cin>>sr>>sc;
	scanf("%s %s",s+1,t+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='L')a[i] = -1;
		else if(s[i]=='R')a[i] = 1;
		else a[i] = 0;
		if(t[i]=='L')b[i] = -1;
		else if(t[i]=='R')b[i] = 1;
		else b[i] = 0;
	}
	x = sc;
	if(!check(1,w,w)){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='D')a[i] = 1;
		else if(s[i]=='U')a[i] = -1;
		else a[i] = 0;
		if(t[i]=='D')b[i] = 1;
		else if(t[i]=='U')b[i] = -1;
		else b[i] = 0;
		x = sr;
	}
	if(!check(1,h,h)){
		puts("NO");
		return 0;
	}
	cout << "YES" << endl;
	return 0;
} 
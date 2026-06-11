#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int N=2e5+5;
int n,a[N];
bool check(int m){
	map<int,int> s;
	rep (i,2,n){
		if (a[i-1]<a[i]) continue;
		if (m==1) return 0;
		int x=a[i];
		s.erase(s.upper_bound(x),s.end());
		while (s[x]==m-1){
			x--;
			if (x==0) return 0;
		}
		s.erase(s.upper_bound(x),s.end());
		s[x]++;
	}
	return 1;
}
int main(){	
	scanf("%d",&n);
	rep (i,1,n) scanf("%d",&a[i]);
	int l=1,r=n,mid;
	while (l<=r){
		mid=l+r>>1;
		if (check(mid)) r=mid-1; else l=mid+1;
	}
	printf("%d\n",r+1);
	return 0;
}
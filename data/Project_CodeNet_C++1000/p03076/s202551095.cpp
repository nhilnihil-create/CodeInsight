//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	vector<int>	a(5);
	for(i=0;i<5;i++) cin >> a[i];
	c=10;
	h=0;
	for(i=0;i<5;i++){
		b=a[i]%10;
		if(b!=0){
			a[i]=a[i]-b+10;
			if(b<c){
				c=b;
			}
		}
		h+=a[i];
	}
	printf("%d\n", h-(10-c));
	return 0;
}

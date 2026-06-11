#include <bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=(t);++i) 
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define mp(a,b) make_pair(a,b) 
using namespace std;
const int N=3e5+50; 
int n,a[N]; 

bool chk(int x){
	if(x==1){rep(i,2,n)if(a[i]<=a[i-1])return false; return true; }
	set<pair<int,int>> s; 
	rep(j,2,n){
		if(a[j]<=a[j-1]){
			while(!s.empty()&&(s.rbegin()->first>=a[j]))s.erase(*s.rbegin()); 
			dec(i,a[j]-1,0){
				if(s.empty()||s.rbegin()->first!=i){
					s.insert(mp(i,1));
					break;
				}
				if(s.rbegin()->second+1<x){
					auto t=*s.rbegin(); s.erase(*s.rbegin()); ++t.second; s.insert(t); 
					break;
				}else{
					s.erase(*s.rbegin()); 
				}
			}
			if(s.empty())return false;
		}}
	return true;
}

int main() {
	scanf("%d", &n); 
	rep(i,1,n) scanf("%d",a+i); 
	int l=0,r=n; 
	while(r-l>1){
		int mid=(l+r)>>1;
		if(chk(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r); 
	return 0;
}
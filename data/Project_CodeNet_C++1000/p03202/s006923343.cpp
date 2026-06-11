#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
int a[200005];
int b[200005];
int n;
map<int,int> mp;
bool check(int mid){
	mp.clear();
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]) continue;
		mp.erase(mp.upper_bound(a[i]),mp.end());
		int j;
		for(j=a[i];j>0;j--){
			if(mp[j]<mid){
				mp[j]++;
				break;
			}
			mp.erase(mp.find(j));
		}
		if(j==0) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bool flag=0;
	for(int i=0;i<n-1;i++) if(a[i]>=a[i+1]) flag=1;
	if(!flag){
		cout<<1;
		return 0;
	}
	int l=1,r=n,res=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(!check(mid)){
			l=mid+1;
		}
		else {
			res=mid;
			r=mid-1;
		}
	}
	cout<<res+1;
}
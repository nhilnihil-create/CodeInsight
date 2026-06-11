#include<bits/stdc++.h>
using namespace std;
int a[200003],n;
map<int,int>built;
bool check(int num){
	built.clear();
	int l=0;
	for(int i=0;i<n;i++){
		if(a[i]>l)
			l=a[i];
		else{
			while(!built.empty()&&built.rbegin()->first>=a[i])built.erase(built.rbegin()->first);
			int c=a[i]-1; 
			built[c]++;
			while(built[c]>=num){
				built.erase(c);
				c--;
				built[c]++;
				if(c<0)return 0;
			}
			l=a[i];
		}
	}
	return 1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	bool k=1;
	for(int i=1;i<n;i++)
		if(a[i]<=a[i-1])
			k=0;
	if(k){
		cout<<1;
		return 0;
	}
	int l=1,r=n+1;
	while(r>l+1){
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	cout<<r;
}
#include<bits/stdc++.h>
using namespace std;
int n,num[200011];
bool che_up(){
	for(int i=1;i<n;i++)if(num[i]<=num[i-1])return false;
	return true;
}
bool che(int ip){
	map<int,int>m;
	int len=0;
	for(int i=0;i<n;i++){
		if(num[i]>len){len=num[i];continue;}
		while(!m.empty()&&m.rbegin()->first>=num[i])m.erase(m.rbegin()->first);
		m[num[i]-1]++;
		int now=num[i]-1;
		while(m[now]>=ip){
			m.erase(now--),m[now]++;
			if(now<0)return false;
			len=num[i];
		}
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&num[i]);
	if(che_up()){puts("1");return 0;}
	int l=1,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(che(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
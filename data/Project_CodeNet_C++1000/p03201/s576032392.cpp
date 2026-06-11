#include<bits/stdc++.h>
using namespace std;
typedef vector<int>VI;
int n;
VI a;
int work(VI a,int d){
	if(d<0)return 0;
	int i=0,j=a.size()-1,ans=0;
	VI b;
	for(;i<j;++i){
		for(;i<j-1 && a[i]+a[j]>(1<<d);--j);
		if(a[i]+a[j]==(1<<d))++ans,a[i]=a[j--]=-1;
	}
	for(int x:a)if(x!=-1)b.push_back(x);
	ans+=work(b,d-1);return ans;
}
int main(){
	scanf("%d",&n);a.resize(n);for(int&x:a)scanf("%d",&x);
	sort(a.begin(),a.end());
	printf("%d\n",work(a,30));
	return 0;
}
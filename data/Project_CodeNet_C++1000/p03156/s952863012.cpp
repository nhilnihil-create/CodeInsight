#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a,b,res1,res2,res3,store[110],res;
signed main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)cin>>store[i];
	sort(store,store+n);
	int cnt=0;
	while(cnt<n&&store[cnt]<=a)cnt++;
	res1=cnt;
	while(cnt<n&&store[cnt]>=a+1&&store[cnt]<=b)cnt++;
	res2=cnt-res1;
	while(cnt<n&&store[cnt]>=b+1)cnt++;
	res3=cnt-(res2+res1);
	res=min(res1,res2);
	res=min(res,res3);
	cout<<res<<endl;
	return 0;
}
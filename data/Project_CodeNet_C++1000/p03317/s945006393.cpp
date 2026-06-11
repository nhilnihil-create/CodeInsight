#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int n,k,ans=0;
	cin>>n>>k;
	int a[n];
	rep(i,n)cin>>a[i];
	n-=k;
	ans+=n/(k-1)+1;
	if(n%(k-1))ans++;
	cout<<ans<<endl;
	return 0;
}
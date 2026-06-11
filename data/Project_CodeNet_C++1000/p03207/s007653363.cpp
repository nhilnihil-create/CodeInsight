#include<iostream>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int n,ans=0;
	cin>>n;
	int p[n];
	rep(i,n)cin>>p[i];
	sort(p,p+n);
	rep(i,n){
		if(i==n-1)ans+=p[i]/2;
		else ans+=p[i];
	}
	cout<<ans<<endl;
	return 0;
}
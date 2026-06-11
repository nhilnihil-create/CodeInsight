#include <iostream>
#include <algorithm>
#include <vector>
#include <map> 
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back

int main(int argc, char** argv) {
	int n,a,b;
	cin>>n>>a>>b;
	int p=(n-b);
	if(n<b+a-1)
	{
		cout<<-1;
		return 0;
	}
	if((n/b+((n%b)?1:0))>a||(n/a+((n%a)?1:0))>b)
	{
		cout<<-1;
		return 0;
	}
	vector<int>ans;
	;
	ans.pb(b);
	a--;
	while(a)
	{
		int u=min(b,p-(a-1));
		p-=u;
	//	cout<<u<<endl;
		a--;
		ans.pb(u);
	}
	int low=0,hig=0;
	rep(i,0,ans.size()-1)
	{
		low=hig;
		hig=hig+ans[i];
		//cout<<hig<<endl;
		rep2(j,hig,low+1)printf("%d ",j);
	}
	return 0;
}
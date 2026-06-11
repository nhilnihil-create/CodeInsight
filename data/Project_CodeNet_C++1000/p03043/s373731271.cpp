#include<bits/stdc++.h>
using namespace std;

#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,k;
	cin>>n>>k;
	double ans=0.0;
	for(int i=1;i<=n;i++){
		double p=(double)1/n;
		int sum=i;
		while(sum<k){
			sum*=2;
			p=p*(0.500);
			//cout<<p<<endl;
		}
		//cout<<ans<<' '<<p<<endl;	
		ans+=p;
	}
	cout<<ps(ans,20)<<endl;

	return 0;
}
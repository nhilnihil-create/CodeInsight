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
	int n,m,a,b,m1=-1,m2=INT_MAX;;
	cin>>n>>m;
	//vector<pair<int,int>> v;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		//v.push_back({a,b});
		m1=max(m1,a);
		m2=min(m2,b);
	} 
	if(m2-m1+1<0)
		cout<<"0\n";
	else
		cout<<m2-m1+1<<endl;
	return 0;
}
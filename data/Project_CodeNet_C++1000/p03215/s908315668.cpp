#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
 
const int MAX_N=1005;
int n,m;
LL a[MAX_N];
vector<LL> v1,v2;
 
void Build();
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
	{
		LL ss=0;
		for(int j=i;j<n;++j)
		{
			ss+=a[j];
			v1.push_back(ss);
		}
	}
	LL ans=0;
	for(int i=40;i>=0;--i)
	{
		v2.clear();
		LL p=((LL)1<<i);
		for(auto c:v1)
			if(c&p)	v2.push_back(c);
		if(v2.size()>=m){
			ans+=p;
			v1.clear();	v1=v2;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
#include <iostream>
using namespace std;
const int INF=0x3f3f3f3f;
//vector<int>v[maxn];
//map<int,string>mp[maxn];
//queue<int>q[maxn];
int n,m;
long long gcd(long long a,long long b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	int i,j,k,ans=0;
	long long x,y,z,w;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y>>z>>w;		if(w<y || x<y)
		{
			cout<<"No"<<endl;continue;
}
		if(z+1>=y){
						cout<<"Yes"<<endl;continue;
		}



		long long g=gcd(y,w);
		if((x-z-1ll)/g-(x-y)/g<=0)
            cout<<"Yes"<<endl;
       	else
            cout<<"No"<<endl;
	}
	return 0;
}

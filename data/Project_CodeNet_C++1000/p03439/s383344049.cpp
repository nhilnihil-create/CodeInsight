#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int query(int i)
{
	cout<<i<<endl;
	flush(cout);
	string res;
	cin>>res;
	if(res=="Male")
		return 1;
	else if(res=="Female")
		return -1;
	return 0;
}
int main()
{
	int n,tmp,yosou;
	ll ans=0;
	cin>>n;
	int l=0;int r=n;
	int lz,rz;
	tmp=query(0);
	if(tmp==0)
		return 0;
	lz=tmp;
	rz=tmp;
	while(1)
	{
		int mid=(l+r)/2;
		if((mid-l)&1)
			yosou=lz*-1;
		else
			yosou=lz;
		tmp=query(mid);
		if(tmp==0)
			break;
		if(yosou==tmp)
		{
			l=mid;
			lz=tmp;
		}else{
			r=mid;
			rz=tmp;
		}
	}
	return 0;
}
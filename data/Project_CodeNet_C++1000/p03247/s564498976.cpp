#include <iostream>
#include <vector>
using namespace std;
long long a[1005],b[1005];
vector <long long> v;
string ans[1005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i] >> b[i];
	for(int i=2;i<=n;i++)
	{
		if((a[i]+b[i]&1)!=(a[i-1]+b[i-1]&1))
		{
			puts("-1");
			return 0;
		}
	}
	if(!(a[1]+b[1]&1))
	{
		v.push_back(1);
		for(int i=1;i<=n;i++)
		{
			ans[i]+='L';
			++a[i];
		}
	}
	int now=1;
	for(int i=1;i<=30;i++)
	{
		v.push_back(now);
		for(int j=1;j<=n;j++)
		{
			if(a[j]&now)
			{
				if((b[j]&(now<<1))==(a[j]&(now<<1)))
				{
					a[j]+=now;
					ans[j]+='L';
				}
				else
				{
					a[j]-=now;
					ans[j]+='R';
				}
			}
			else
			{
				if((a[j]&(now<<1))==(b[j]&(now<<1)))
				{
					b[j]+=now;
					ans[j]+='D';
				}
				else
				{
					b[j]-=now;
					ans[j]+='U';
				}
			}
		}
		now<<=1;
	}
	v.push_back(now);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0) ans[i]+='L';
		if(a[i]>0) ans[i]+='R';
		if(b[i]<0) ans[i]+='D';
		if(b[i]>0) ans[i]+='U';
	}
	cout << v.size() << "\n";
	for(auto x:v) cout << x << " ";
	puts("");
	for(int i=1;i<=n;i++) cout << ans[i] << "\n";
	return 0;
}
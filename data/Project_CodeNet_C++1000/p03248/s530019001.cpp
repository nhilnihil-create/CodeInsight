#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	string a;
	cin >> a;
	int n=a.size();
	a='0'+a;
	for(int i=0;i<=n;i++)
	{
		if(a[i]^a[n-i])
		{
			puts("-1");
			return 0;
		}
	}
	if(a[1]=='0')
	{
		puts("-1");
		return 0;
	}
	int cnt=1,rt=1;
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]=='0') cout << rt << " " << cnt+1 << "\n";
		else
		{
			cout << rt << ' ' << cnt+1 << "\n";
			rt=cnt+1;
		}
		++cnt;
	}
	for(int i=n/2+1;i<n;i++)
	{ 
		++cnt;
		cout << rt << " " << cnt << "\n";
	}
	return 0;
}
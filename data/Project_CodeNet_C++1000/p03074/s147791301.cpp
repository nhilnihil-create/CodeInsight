#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	string a;
	cin >> a;
	a=' '+a;
	int now=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]!='0'&&a[i]=='0')
			--k;
		while(k<0&&now<=i)
		{
			if(a[now]=='0'&&a[now+1]=='1') 
				++k;
			++now;
		}
		if(k>=0) ans=max(ans,i-now+1);
	//	cout << now << " " << i << "\n";
	}
	cout << ans;
	return 0;
}
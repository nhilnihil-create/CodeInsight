#include <iostream>
using namespace std;
int qzh[200005],hzh[200005];
int main(int argc, char** argv) {
	int n,ans=1e9;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin >> x;
		if(x=='#') ++qzh[i];
		else ++hzh[i];
	}
	for(int i=1;i<=n;i++) qzh[i]+=qzh[i-1];
	for(int i=n;i>=1;i--) hzh[i]+=hzh[i+1];
	for(int i=0;i<=n;i++) ans=min(ans,qzh[i]+hzh[i+1]);
	cout << ans;
	return 0;
}
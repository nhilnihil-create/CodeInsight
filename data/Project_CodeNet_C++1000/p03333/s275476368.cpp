#include <iostream>
#include <algorithm>
using namespace std;
long long n,ans,l[100005],r[100005];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie();
	cin>>n;
	for (int i=1;i<=n;++i) cin>>l[i]>>r[i];
	sort(l,l+n+1,greater <long long>());
	sort(r,r+n+1);
	for (int i=0;i<=n;i++) if (l[i]>r[i]) ans+=l[i]-r[i];
	cout<<2*ans<<endl;
	return 0;
}
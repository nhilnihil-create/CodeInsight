#include <bits/stdc++.h>
#define maxn 100101
#define ll long long
int n,l[maxn],r[maxn];ll ans;
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;for (int i=1;i<=n;i++)
	cin>>l[i]>>r[i];
	sort(l,l+1+n);sort(r,r+1+n);
	for (int i=0;i<=n;i++)
	ans+=max(0,l[n-i]-r[i]);
	cout<<ans*2<<endl;return 0;
}
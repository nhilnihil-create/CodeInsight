#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N],a[N];
pair<int ,int >p[N];
int gcd(int a,int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int ans=a[0];
	for(int i=0;i<n;i++)ans=gcd(ans,a[i]);
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[27][102];
string s[3];
int main() {
	ll n,ans=0;
	cin>>n>>s[0]>>s[1]>>s[2];
	for(int i=0;i<n;i++){
		ll sum=0;
		for(int j=0;j<3;j++){
			ll now=s[j][i]-'a';
			a[now][i]++;
			sum=max(sum,a[now][i]);
		}
		ans+=3-sum;
	}
	cout <<ans;
	// your code goes here
	return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=9223372036854775806;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,p,i,j,ans=1,r;
	cin>>p>>n;
	for (i=2;i*i<=n;i++){
		if (n%i==0){
			r=0;
			while (n%i==0){
				n/=i;
				r++;
			}
			j=r/p;
			while (j>0){
				ans*=i;
				j--;
			}
		}
	}
	if (n>1&&p==1){
		ans*=n;
	}
	cout<<ans;
	return 0;
}
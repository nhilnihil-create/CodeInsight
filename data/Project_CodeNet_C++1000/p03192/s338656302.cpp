#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=9223372036854775806;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int ans=0,i;
	string a;
	cin>>a;
	for(i=0;i<a.size();i++){
		if (a[i]=='2'){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
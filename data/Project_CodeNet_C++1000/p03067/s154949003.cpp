#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll infll=9223372036854775806;
const int inf=2147483646;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	if (c<max(a,b)&&c>min(a,b)){
		cout<<"Yes";
	}
	else {
		cout<<"No";
	}
	return 0;
}
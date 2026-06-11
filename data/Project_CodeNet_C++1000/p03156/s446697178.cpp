#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=9223372036854775806;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,a,b,t,i,j,c1=0,c2=0,c3=0;
	cin>>n>>a>>b;
	for (i=0;i<n;i++){
		cin>>t;
		if (t>b){
			c3++;
		}
		else if (t>a){
			c2++;
		}
		else {
			c1++;
		}
	} 
	cout<<min(c1,min(c2,c3));
	return 0;
}
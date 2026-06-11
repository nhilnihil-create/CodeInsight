#define _USE_MATH_DEFINES //M_PI, M_E
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a[3][3];
	for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) cin>>a[i][j];
	int flag = 0;
	for(int b = -100000; b<=100000; b++)
	{
		int b1 = a[0][0]-b, b2 = a[0][1]-b, b3 = a[0][2]-b;
		int a2 = a[1][0]-b1,a3 = a[2][0]-b1;
		if(a2+b2==a[1][1] && a2+b3==a[1][2] && a3+b2==a[2][1] && a3+b3 == a[2][2]) flag = 1;
		if(flag) break;
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
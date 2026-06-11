#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int h,w,d,q,x[100005],y[100005];
int main()
{
	cin >> h >> w >> d;
	long long sum[d][h*w/d+10]={0};
	for(int i=0,k; i<h; i++) for(int j=0; j<w; j++) cin >> k,x[k]=i,y[k]=j;
	for(int i=0; i<d; i++) 
		for(int j=1; i+d*j<=h*w; j++) sum[i][j]=sum[i][j-1]+abs(x[i+d*j]-x[i+d*j-d])+abs(y[i+d*j]-y[i+d*j-d]);
	cin >> q;
	for(int i=0,l,r; i<q; i++)
	{
		cin >> l >> r;
		cout << sum[l%d][r/d]-sum[l%d][l/d] << '\n';
	}
	return 0;
}

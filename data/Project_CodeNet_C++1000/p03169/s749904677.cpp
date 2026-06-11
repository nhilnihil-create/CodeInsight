#include <bits/stdc++.h>
#define N 301
using namespace std;


int n, a, b, c, x;
double dp[N][N][N];


double f(int a, int b, int c) {
	if (a==0 && b==0 && c==0) return 0;
	if (a<0 || b<0 || c<0) return 0;
	if (dp[a][b][c]!=0) return dp[a][b][c];
	double ea, eb, ec, ans;
	ea = f(a-1,b,c);
	eb = f(a+1,b-1,c);
	ec = f(a,b+1,c-1);
	ans = (a*ea+b*eb+c*ec+n)/(a+b+c);
	//printf("(%d %d %d) -> %.2lf\n",a,b,c,ans);
	return dp[a][b][c]=ans;
}


int main() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>x;
		if (x==1) a++;
		if (x==2) b++;
		if (x==3) c++;
	}
	printf("%.20lf\n",f(a,b,c));
	return 0;
}
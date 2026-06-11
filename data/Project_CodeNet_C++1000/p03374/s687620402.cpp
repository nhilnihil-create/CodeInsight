#include<iostream>  
#include<cstdlib>  
#include<string>  
#include<ctime>  
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100005] = { 0 };
long long b[100005] = { 0 };
long long x[100005] = { 0 };
long long v[100005] = { 0 };
 int main()
{
	 long long n, c,ans=0;
	 cin >> n >> c;
	 for (int i = 1; i <= n; i++)
	 {
		 cin >> x[i] >> v[i];
	 }
	 x[n + 1] = c;
	 b[n + 1] = 0;
	 for (int i = 1; i <= n; i++)
	 {
		 a[i] = a[i - 1] + v[i] - (x[i] - x[i - 1]);
	 }
	 for (int i = n; i > 0; i--)
	 {
		 b[i] = b[i + 1] + v[i] - (x[i + 1] - x[i]);
	 }
	 for (int i = 2; i <= n; i++)
	 {
		 a[i] = max(a[i - 1], a[i]);
	 }
	 for (int i = n-1; i > 0; i--)
	 {
		 b[i] = max(b[i + 1], b[i]);
	 }
	 for (int i = 1; i <= n; i++)
	 {
		 ans = max(ans, a[i]);
		 ans = max(ans, b[i]);
		 ans = max(ans,a[i]+ b[i + 1]-x[i]);
		 ans = max(ans, a[i - 1] + b[i] - (c - x[i]));
	 }
	 cout << ans << endl;
	return 0;
}
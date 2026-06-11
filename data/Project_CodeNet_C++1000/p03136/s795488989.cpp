#include<cstdio>
#include<algorithm>
#define ll long long
#define rep(i, l, r) for(int i=l; i<=r; ++i)
#define N 200005
#define mod 1000000007
using namespace std;
int t;
int n;
int a[N];
int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	bool f=false;
	rep(i, 1, n-1){
		a[n]-=a[i];
		if(a[n]<0) f=true;
	}
	printf(f ? "Yes" : "No");
	return 0;
}
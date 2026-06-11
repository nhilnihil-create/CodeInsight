#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

int main() {
	string s;cin>>s;
	int n=s.size();
	ll p[N],a[N],b[N],c[N];

	if(s[0]=='?') p[0]=3;
	else p[0]=1;
	for(int i=1;i<n;i++){
		if(s[i]=='?') p[i]=3*p[i-1];
		else p[i]=p[i-1];
		p[i]%=MOD;
	}

	if(s[0]=='A'||s[0]=='?') a[0]=1;
	else a[0]=0;
	for(int i=1;i<n;i++){
		if(s[i]=='A') a[i]=a[i-1]+p[i-1];
		else if(s[i]=='?') a[i]=3*a[i-1]+p[i-1];
		else a[i]=a[i-1];
		a[i]%=MOD;
	}

	b[0]=0;
	for(int i=1;i<n;i++){
		if(s[i]=='B') b[i]=a[i-1]+b[i-1];
		else if(s[i]=='?') b[i]=a[i-1]+3*b[i-1];
		else b[i]=b[i-1];
		b[i]%=MOD;
	}

	c[1]=0;
	for(int i=2;i<n;i++){
		if(s[i]=='C') c[i]=b[i-1]+c[i-1];
		else if(s[i]=='?') c[i]=b[i-1]+3*c[i-1];
		else c[i]=c[i-1];
		c[i]%=MOD;
	}

	cout<<c[n-1]<<endl;
}

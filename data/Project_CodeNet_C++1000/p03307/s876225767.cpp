#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define gap ' '
#define L(i) ((i) - (&i))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)

const int MAXN = 1000111;
const int mxn = 1e5+10;
const int MAX = 1e6 + 1;
const int MOD = 1e9;
const int INF = 1e9;

int main(){
	int n; cin >> n;
	if(n % 2 == 0)
		cout << n << "\n";
	else
		cout << (ll)2*n << "\n";
	return 0;
}
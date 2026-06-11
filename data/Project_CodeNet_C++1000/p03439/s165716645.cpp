#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
	int N; cin >> N;
	cout << 0 << endl;
	fflush(stdout);
	string s; cin >> s;
	if(s[0] == 'V') return 0;
	int ok = 0;
	int ng = N-1;
	while(ok+2 != ng){
		int mid = (ok+ng)/2;
		if(mid & 1) mid += 1;
		cout << mid << endl;
		fflush(stdout);
		string t; cin >> t;
		if(t[0] == 'V') return 0;
		if(t == s) ok = mid;
		else ng = mid;
	}
	cout << ok+1 << endl;
	fflush(stdout);
	string m; cin >> m;
	if(m[0] == 'V') return 0;
	cout << ng << endl;
	fflush(stdout);
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
	int N,Q;
	string str;
	cin >> N >> Q >> str;
	int l[Q],r[Q];
	vector<int> s(N);
	for(int i = 0; i < Q; i++) cin >> l[i] >> r[i], l[i]--,r[i]--;
	s[0] = 0;
	for(int i = 0; i < N -1; i++)
	{
		if(str[i] == 'A' && str[i + 1] == 'C') s[i + 1] = s[i] + 1;
		else s[i + 1] = s[i];
	}
	for(int i = 0; i < Q; i++)
	{
		cout << s[r[i]] - s[l[i]] << endl;
	}
}
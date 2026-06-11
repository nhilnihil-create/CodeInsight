#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
#define INF 1e15
#define MOD 1000000007
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef long long ll;
#define END system("PAUSE");return 0
string s;
int a[3];
signed main() {
	cin >> s;
	rep(i, s.size())a[s[i] - 'a']++;
	sort(a, a + 3);
	if (a[2] - a[0] <= 1)puts("YES");
	else puts("NO");
	END;
}

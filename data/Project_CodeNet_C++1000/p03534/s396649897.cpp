#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
#include<random>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define int long long
#define inf 1145141919
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;
typedef pair<int, P> PP;
struct edge { int to, cost; };
const long long mod = 1000000007;

signed main() {
	string s; cin >> s;
	int a = 0, b = 0, c = 0;
	rep(i, s.size()) {
		if (s[i] == 'a')a++;
		else if (s[i] == 'b')b++;
		else c++;
	}
	if (max(a, max(b, c)) - min(a, min(b, c)) > 1)puts("NO");
	else puts("YES");
}
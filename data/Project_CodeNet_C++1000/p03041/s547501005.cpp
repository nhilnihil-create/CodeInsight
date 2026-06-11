#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int a = int(s[k -1]);
	a += 32;
	s[k -1] = char(a);
	cout << s;
	return 0;
}
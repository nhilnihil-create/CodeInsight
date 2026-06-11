#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	string s;
	cin >> s;
	int i; int n = s.length();
	int count[3] = {};
	for (i = 0; i < n; i++) {
		count[(s[i] - 'a')]++;
	}
	sort(count, count + 3);
	if (count[2] - count[0] <= 1)cout << "YES" << endl;
	else cout << "NO" << endl;
	char nyaa;
	std::cin >> nyaa;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;


int main(){
	int n, m;
	cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		string s;
		cin >> s;
		mp[s]--;
	}
	int ans = 0;
	for (auto x : mp){
		ans = max(ans, x.second);
	}
	cout << ans << endl;
	return 0;
}
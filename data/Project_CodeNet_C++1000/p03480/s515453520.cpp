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
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
using namespace std;


int main(){
	string s;
	cin >> s;
	int ans = s.length();
	for (int i = 0; i < s.length()-1; i++){
		if (s[i] != s[i+1]){
			int temp = max(i+1, (int)s.length()-i-1);
			ans = min(temp, ans);
		}
	}
	cout << ans << endl;
	return 0;
}

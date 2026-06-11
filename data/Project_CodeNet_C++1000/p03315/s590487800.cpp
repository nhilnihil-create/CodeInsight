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
	int ans = 0;
	string s;
	cin >> s;
	for (auto x : s){
		if (x == '-') ans --;
		else ans++;
	}
	cout << ans << endl;
	return 0;
}
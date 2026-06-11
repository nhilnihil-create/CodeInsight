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
	string s;
	cin >> s;
	int ans = 700;
	for (int i = 0; i < 3; i++){
		if (s[i] == 'o'){
			ans += 100;
		}
	}
	cout << ans << endl;
	return 0;
}

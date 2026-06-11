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
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = a; i <= b; i++){
		string s = to_string(i), t = to_string(i);
		reverse(t.begin(), t.end());
		if (s == t){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
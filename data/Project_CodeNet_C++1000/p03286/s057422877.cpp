#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;


int main(){
	int n;
	string s;
	cin >> n;
	if (n == 0){
		cout << 0 << endl;
		return 0;
	}
	for (;;){
		if (n == 0) break;
		if (n % 2 == 1){
			s += '1';
			n /= -2;
		}else if (n % 2 == 0){
			s += '0';
			n /= -2;
		}else{
			s += '1';
			n = (n-2)/ -2;
		}
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
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

ll num[5];

int main(){
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		if (s[0] == 'M') num[0]++;
		if (s[0] == 'A') num[1]++;
		if (s[0] == 'R') num[2]++;
		if (s[0] == 'C') num[3]++;
		if (s[0] == 'H') num[4]++;
	}

	ll ans = 0; 
	for (int i = 0; i < 3; i++){
		for (int j = i+1; j < 4; j++){
			for (int k = j+1; k < 5; k++){
				ans += num[i]*num[j]*num[k];
			}
		}
	}
	cout << ans << endl;
	return  0;
}
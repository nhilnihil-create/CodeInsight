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
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++){
		bool alpha[26];
		bool used[26];
		for (int j = 0; j < 26; j++){
			alpha[j] = false;
			used[j] = false;
		}
		int coun = 0;
		for (int j = 0; j < i; j++){
			alpha[s[j] - 'a'] = true;
		}
		for (int j = i; j < s.length(); j++){
			if (alpha[s[j] - 'a'] && !used[s[j] - 'a']){
				coun++;
				used[s[j] - 'a'] = true;
			}
		}
		ans = max(ans, coun);
	}
	cout << ans << endl;
	return 0;
}

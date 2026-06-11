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

string s;
int k;
vector<string> str; 

int main(){
	cin >> s >> k;

	for (int i = 1; i <= k; i++){
		for (int j = 0; j < s.length() - i + 1; j++){
			str.push_back(s.substr(j, i));
		}
	}

	sort(str.begin(), str.end());
	auto result = unique(str.begin(), str.end());
	str.erase(result, str.end());
	cout << str[k-1] << endl;
	return 0;
}

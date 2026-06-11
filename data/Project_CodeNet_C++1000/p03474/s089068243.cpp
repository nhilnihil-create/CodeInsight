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
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;


int main(){
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	for (int i = 0; i < a; i++){
		if (s[i] == '-'){
			cout << "No" << endl;
			return 0;
		}
	}
	if (s[a] != '-'){
		cout << "No" << endl;
		return 0;
	}
	for (int i = a+1; i <= a+b+1; i++){
		if (s[i] == '-'){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
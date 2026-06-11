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
	cin >> n;
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		if (c == 'Y'){
			cout << "Four" << endl;
			return 0;
		}
	}
	cout << "Three" << endl;
	return  0;
}
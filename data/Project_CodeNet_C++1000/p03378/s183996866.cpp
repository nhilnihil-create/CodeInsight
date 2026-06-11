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

bool is_money[101];

int main(){
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++){
		int y;
		cin >> y;
		is_money[y] = true;
	}
	int coun1 = 0, coun2 = 0;
	for (int i = 0; i <= x; i++){
		if (is_money[i]) coun1++;
	}

	for (int i = x; i <= n; i++){
		if (is_money[i]) coun2++;
	}

	cout << min(coun1, coun2) << endl;
	return 0;
}


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
	int n, d, x;
	cin >> n >> d >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> vec;
	for (int i = 0; i <= 100; i++){
		for (int j = 0; j < n; j++){
			vec.push_back(a[j]*i+1);
		}
	}
	int coun = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; ; i++){
		if (vec[i] > d) break;
		coun++;
	}
	cout << x + coun << endl;
}


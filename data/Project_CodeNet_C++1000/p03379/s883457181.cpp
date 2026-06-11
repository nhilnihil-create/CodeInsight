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
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++){
		cin >> x[i];
		y[i] = x[i];
	}
	sort(x.begin(), x.end());
	int midsmall = x[n/2-1];
	int midlarge = x[n/2];

	for (int i = 0; i < n; i++){
		if (y[i] <= midsmall){
			cout << midlarge << endl;
		}else{
			cout << midsmall << endl;
		}
	}
	return 0;
}


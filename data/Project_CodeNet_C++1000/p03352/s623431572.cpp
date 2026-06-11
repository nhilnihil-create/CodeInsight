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
	int x;
	cin >> x;
	if (x <= 3){
		cout << 1 << endl;
		return 0;
	}

	vector<int> vec;
	for (int i = 2; i < 40; i++){
		if (pow(i, 2) <= x){
			int tmp = 2;
			while (pow(i, tmp) <= x){
				tmp++;
			}
			vec.push_back(pow(i, tmp-1));
		}
	}
	sort(vec.begin(), vec.end(), greater<int>());
	cout << vec[0] << endl;
	return 0;
}

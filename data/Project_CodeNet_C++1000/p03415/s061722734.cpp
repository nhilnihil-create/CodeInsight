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
	char c[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < 3; i++){
		cout << c[i][i];
	}
	cout << endl;
	return 0;
}
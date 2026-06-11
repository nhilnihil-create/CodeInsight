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

int sigma(int n){
	int coun = 0;
	for (int i = 1; i <= n; i++){
		coun += i;
	}
	return coun;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << sigma(b-a) - b << endl;
	return 0;
}
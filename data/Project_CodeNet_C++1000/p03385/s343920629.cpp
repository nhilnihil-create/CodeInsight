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
	string s;
	cin >> s;
	if (s == "abc" || s == "acb" || s == "bac" || s == "bca" || s == "cab" || s == "cba"){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return  0;
}
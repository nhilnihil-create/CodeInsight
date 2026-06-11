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

bool is_prime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x % i == 0) return false;
	}
	return true;
}


int main(){
	int n;
	cin >> n;
	int coun = 0;
	for (int i = 2; i <= 55555; i++){
		if (is_prime(i)){
			string s = to_string(i);
			if (s[s.length()-1] == '1'){
				cout << i << endl;
				coun++;
			}
			if (coun == n) return 0;
		}
	}
	return 0;
}

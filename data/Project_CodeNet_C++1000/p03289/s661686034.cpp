#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

int getC(string s){
	int c = 0;
	for (int i = 2; i < s.length(); i++){
		if (s[i] == 'C'){
			if (c != 0) return -1;
			c = i;
		}
	}
	return c;
}

bool is_small(char c){
	if (c >= 'a' && c <= 'z') return true;
	return false;
}


int main(){
	string s;
	cin >> s;
	if (s[0] == 'A'){
		if (getC(s) >= 2 && getC(s) < s.length()-1){
			int temp = getC(s);
			for (int i = 1; i < s.length(); i++){
				if (i == temp) continue;
				if (!is_small(s[i])){
					cout << "WA" << endl;
					return 0;
				}
			}
			cout << "AC" << endl;
			return 0;
		}
	}
	cout << "WA" << endl;
	return 0;
}

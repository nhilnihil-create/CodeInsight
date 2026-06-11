#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

vector<int> divisor;



string swap19(string s){
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '9'){
			s[i] = '1';
		}else if(s[i] == '1'){
			s[i] = '9';
		}
	}
	return s;
}

int main(){
	string s;
	cin >> s;
	cout << swap19(s) << endl;
}
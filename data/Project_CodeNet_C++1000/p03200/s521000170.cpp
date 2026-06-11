#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)


int main() {
	string s;
	
	cin >> s;
	int len = (int)(s.size());
	long long int ans = 0,x = 0;
	rep(i,len){
		if(s[i] == 'W'){
			ans += x;
		}
		else if(s[i] == 'B'){
			x++;
		}
	}
	
	cout << ans << endl;
	return 0;
}
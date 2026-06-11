#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
	int in[4];
	string s;
	cin >> s;
	REP(i,4){
		in[i] = (int)(s[i]-'0');
	}
	
	int bit;
	for(bit=0; bit<(1<<3); ++bit){
		int ans = in[0];
		REP(i,3){
			if(bit & (1<<i)){
				ans += in[i+1];
			}else{
				ans -= in[i+1];
			}
		}
		if(ans==7){
			break;
		}
	}
	
	REP(i,3){
		cout << in[i];
		if(bit & (1<<i)) cout << "+";
		else cout << "-";
	}
	cout << in[3] << "=7\n";
	
	return 0;
	
}
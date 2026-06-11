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
#define vint vector<int>


int main(){
	string s;
	cin >> s;
	
	bool a[2]; // [前半 後半]
	
	int zen,kou;
	zen = 10*(int)(s[0]-'0') + (int)(s[1]-'0');
	kou = 10*(int)(s[2]-'0') + (int)(s[3]-'0');
	
	if(1 <= zen && zen <= 12) a[0] = true;
	else a[0] = false;
	if(1 <= kou && kou <= 12) a[1] = true;
	else a[1] = false;
	
	if(a[0] && a[1]) cout << "AMBIGUOUS\n";
	else if(a[0]) cout << "MMYY\n";
	else if(a[1]) cout << "YYMM\n";
	else cout << "NA\n";
	
	
	return 0;
}
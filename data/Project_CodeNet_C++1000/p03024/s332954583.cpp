#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int cnt=0, l=s.length();
	for(int i=0; i<l; i++){
		if(s[i]=='o') cnt++;
	}
	if(cnt+7-l>=0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
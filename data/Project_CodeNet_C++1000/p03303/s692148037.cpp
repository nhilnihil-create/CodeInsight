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

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s;
	int w;
	cin >> s >> w;
	for(int i=0; i<s.length(); i+=w) cout << s[i];
	cout << endl;
	return 0;
}
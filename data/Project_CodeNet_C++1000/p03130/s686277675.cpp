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
	vector<int> c(4,0);
	for(int i=0; i<3; i++){
		int a, b;
		cin >> a >> b;
		c[a-1]++;
		c[b-1]++;
	}
	sort(c.begin(), c.end());
	if(c[0]==1 && c[1]==1 && c[2]==2 && c[3]==2) cout << "YES" << endl;
	else cout << "NO" << endl;
 	return 0;
}
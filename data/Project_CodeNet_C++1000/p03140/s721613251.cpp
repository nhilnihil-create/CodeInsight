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
	int n;
	string s[3];
	cin >> n >> s[0] >> s[1] >> s[2];
	int ans=0;
	for(int i=0; i<n; i++){
		int c=0;
		if(s[0][i]!=s[1][i]) c++;
		if(s[1][i]!=s[2][i]) c++;
		if(s[2][i]!=s[0][i]) c++;
		ans+=max(c-1,0);
	}
	cout << ans << endl;
	return 0;
}
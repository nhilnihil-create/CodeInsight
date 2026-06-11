#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	char s[301][301];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> s[i][j];
		}
	}
	long long int ans = 0;
	for(int a = 0; a < n; a++){
		bool ok = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s[(i - a + n) % n][j] != s[(j - a + n) % n][i]) ok = false;
			}
		}
		if(ok) ans += n;
	}
	cout << ans << endl;
}
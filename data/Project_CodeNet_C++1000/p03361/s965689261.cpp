#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    string s[50] = {};
    for (int i = 0 ; i < h ; i++) cin >> s[i];
    for (int i = 0 ; i < h ; i++) {
        for (int j = 0 ; j < w; j++) {
            if ( s[i][j] == '#' ) {
        		bool y = 0;
        		if (i && s[i - 1][j] == '#') y = 1;
        		if (i + 1 < h && s[i + 1][j] == '#') y = 1;
        		if (j && s[i][j - 1] == '#') y = 1;
        		if (j + 1 < w && s[i][j + 1] == '#') y = 1;
        		if (y == 0) {
					cout << "No";
					return 0;
				}
			}
        }
    }
    cout << "Yes";
}

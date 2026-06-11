#include <iostream>
#include<cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	char a[h + 2][w + 2];
	for (int i = 0 ; i <= h + 1 ; i++) {
        for (int j = 0 ; j <= w + 1 ; j++) {
            if (i == 0 || j == 0 || i == h + 1 || j ==  w + 1) a[i][j] = '.';
            else cin >> a[i][j];
        }
        cout << endl;
    }
	 for (int i = 1 ; i <= h ; i++) {
        for (int j = 1 ; j <= w ; j++) {
            int c = 0;
            if( a[i][j] == '#' ) cout << '#';
            else {
                if (a[i - 1][j - 1] == '#') c++;
                if (a[i - 1][j] == '#') c++;
                if (a[i - 1][j + 1] == '#') c++;
                if (a[i][j - 1] == '#') c++;
                if (a[i][j + 1] == '#') c++;
                if (a[i + 1][j - 1] == '#') c++;
                if (a[i + 1][j] == '#') c++;
                if (a[i + 1][j + 1] == '#') c++;
                cout << c;
            }
        }
        cout << endl;
    }
}

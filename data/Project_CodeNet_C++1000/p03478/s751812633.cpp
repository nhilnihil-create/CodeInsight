#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , a , b;
    cin >> n >> a >> b;
    int x= 0;
    for (int i = 1; i <= n ; i++ ) {
        int y = i;
        int t = 0;
        while ( y >= 1 ) {
             t+= y % 10;
            y /= 10;
        }
        if ( t >= a && t <= b ) x += i;
    }
    cout << x;
}
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a = 2;
    while ( n > 0 ) {
        int b = 1;
        if( a % 5 != 1 ) b = 0;
        for ( int i = 2 ; i * i <= a ; i++ ) {
            if ( a % i == 0 ) b = 0;
        }
        if ( b == 1 ) {
            n--;
            cout << a << ' ';
        }
        a++;
    }
}

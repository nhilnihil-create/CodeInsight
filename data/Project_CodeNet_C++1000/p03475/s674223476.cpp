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
    int n;
    cin >> n;
    int c[n] , s[n] , f[n];
    for( int i = 0 ; i < n - 1 ; i++ ) cin >> c[i] >> s[i] >> f[i];
    for( int i = 0 ; i < n - 1 ; i++ ){
        ll t = c[i] + s[i];
        for( int j = i + 1 ; j < n - 1 ; j++ ){
            if( t < s[j] ) t = s[j];
            else if( t % f[j] == 0 );
            else t = t + f[j] - t % f[j];
            t += c[j];
        }
        cout << t << endl;
    }
    cout << "0";
}

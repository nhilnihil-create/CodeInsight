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
    int n , d , x , c = 0;
    cin >> n >> d >> x;
	int a[n];
	for( int i = 0 ; i < n ; i++ ) cin >> a[i];
	for( int i = 0 ; i < n ; i++ ) {
		for( int j = 0 ; j <= ( d - 1 ) / a[i] ; j++ ) c++;
	} 
	cout << c + x;
} 
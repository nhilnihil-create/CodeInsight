#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n , x = 0;
    cin >> n;
    int a[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    sort( a , a + n );
    int b[100005];
    for( int i = 1 ; i <= min(n, a[n - 1]) ; i++ ) b[i] = 0;
    for (int i = 0; i < n; i++) if (a[i] > n) x++;
    for( int i = 0 ; i < n ; i++ ) if (a[i] <= n) {
        b[a[i]]++;
    }
    for( int i = 1 ; i <= min(n, a[n - 1]) ; i++ ) {
        if( b[i] > 0 ) {
            if( i != b[i] ) {
                if( b[i] > i ) x += b[i] - i;
                else x += b[i];
            }
        }
    }
    cout << x;
}

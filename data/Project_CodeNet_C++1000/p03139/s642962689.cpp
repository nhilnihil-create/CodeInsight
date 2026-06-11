#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 1000;
long long int a[N], b[N] , c[N] , ansa , ans;
pair <long long int , long long int> p[N];

int main () {
    long long int n , a , b;
    cin >> n >> a >> b;
    cout << min(min(a , b) , n) << ' ';
    if(n - a - b < 0) {
        cout << a + b - n;
    }
    else {
        cout << 0;
    }
}

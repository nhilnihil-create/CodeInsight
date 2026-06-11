#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 1000;
long long int a[N], b[N] , c[N] , ansa , ans;
pair <long long int , long long int> p[N];
long long int aa , bb , cc;

int main () {
    long long int n;
    cin >> n;
    string a , b , c;
    cin >> a >> b >> c;
    for(long long int i = 0 ; i < n ; i++ ) {
        if(a[i] == b[i] && c[i] != b[i]) {
            cc++;
        }
        if(c[i] == b[i] && a[i] != b[i]) {
            cc++;
        }
        if(a[i] == c[i] && a[i] != b[i]) {
            cc++;
        }
        if(a[i] != b[i] && a[i] != c[i] && b[i] != c[i]) {
            cc+=2;
        }
    }
    cout << cc;
}

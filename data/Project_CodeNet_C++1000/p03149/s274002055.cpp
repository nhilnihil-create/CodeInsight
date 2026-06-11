#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
#include <stdlib.h>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
int main() {
    vl a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(),a.end());
    if (a[0]==1 && a[1]==4 && a[2]==7 && a[3]==9){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}

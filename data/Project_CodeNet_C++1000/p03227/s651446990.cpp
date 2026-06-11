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
    string a;
    cin >> a;
    if (a.size()==3){
        cout << a[2] << a[1] << a[0] << endl;
        return 0;
    }
    cout << a << endl;
    return 0;
}

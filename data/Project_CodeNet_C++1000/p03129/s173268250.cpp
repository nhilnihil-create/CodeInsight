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
    ll  a,b;
    cin >> a >>b;
    if (a/2+a%2>=b){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}

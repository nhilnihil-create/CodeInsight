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
    ll a,b;
    cin >> a >> b;
    if (a*b==15){
        cout << "*" << endl;
        return 0;
    }else if (a+b==15){
        cout << "+" << endl;
        return 0;
    }
    cout << "x" << endl;
    return 0;
}

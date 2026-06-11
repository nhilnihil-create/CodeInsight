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
    ll  a,b,c;
    cin >> a >> b >> c;
    if (a==b && b==c){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}

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

int main(){
    ll a,b;
    cin >> a >> b;
    if (a%b==0){
        cout << -1 << endl;
        return 0;
    }
    cout << a << endl;
    return 0;
}

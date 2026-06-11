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
    string a;
    ll ans=0;
    cin >> a;
    for (ll i=0;i<4;++i){
        if (a[i]=='2'){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

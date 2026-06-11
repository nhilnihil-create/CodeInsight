#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <map>
typedef long long ll;
using namespace std;
void saiki(ll &c, int tmp, map<ll,ll> m) {
    if (tmp % 2 == 0) {
        tmp = tmp / 2;
    } else {
        tmp = 3 * tmp + 1;
    }
    if (m.count(tmp)) return;
    m[tmp] = 1;
    c = c+1;
    saiki(c,tmp,m);
}

int main(void){
    ll s; cin >> s;
    map<ll,ll> m; 
    ll counter = 2;
    m[s] = 1;
    saiki(counter, s, m);
    cout << counter << endl;
}
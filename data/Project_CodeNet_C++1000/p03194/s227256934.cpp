#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(a) cout << (a) << endl;
typedef long long Int;
Int mod = 1e9+7;
Int MOD = 998244353;

int main() {
    Int n, p;
    cin >> n >> p;
    if (n == 1) {
        dump(p);
        return 0;
    }
    Int c = 0;
    Int res = 1;
    while (p%2 == 0) {
        p /= 2;
        c++;
        if (c%n == 0) res *= 2;
    }
    for (Int i = 3; i*i <= p; i+=2) {
        if (i != 3 && i%3 == 0) continue;
        if (i != 5 && i%5 == 0) continue;
        if (i != 7 && i%7 == 0) continue;   
        if (i != 11 && i%11 == 0) continue;   
        if (i != 13 && i%13 == 0) continue;   
        if (i != 17 && i%17 == 0) continue;   
        if (i != 19 && i%19 == 0) continue;   
        c = 0;
        while (p%i == 0) {
            p /= i;
            c++;
            if (c%n == 0) res *= i;
        }
    }
    dump(res);
    return 0;  
}
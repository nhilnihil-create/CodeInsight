#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main() {
    string S, T;
    cin >> S >> T;
    bool ok = true;
    map<char,char> ma, ima;
    for (int i = 0; i < S.size(); ++i) {
        char s = S[i], t = T[i];
        if (ma.count(s)) if (ma[s] != t) ok = false;
        if (ima.count(t)) if (ima[t] != s) ok = false;
        ma[s] = t; ima[t] = s;
    }
    if (ok) puts("Yes");
    else puts("No");
}
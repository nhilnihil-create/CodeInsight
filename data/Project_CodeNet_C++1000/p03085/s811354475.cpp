#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    char s;
    cin >> s;
    if(s == 'A') puts("T");
    else if(s == 'T') puts("A");
    else if(s=='G') puts("C");
    else puts("G");
}

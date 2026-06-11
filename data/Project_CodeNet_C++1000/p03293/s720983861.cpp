#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)



using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {
    string s,t;
    int n;
    bool ans = false;

    cin >> s >> t;
    n = s.length();
    if(s == t) cout << "Yes";
    else {
        for(int i = 0; i < n; i ++){
            s = s[n-1] + s.substr(0,n-1);
            if(s == t) ans = true;
        }

        cout << ((ans)?"Yes":"No");
    }

    return 0;
}










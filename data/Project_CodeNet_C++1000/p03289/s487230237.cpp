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
    string s;
    bool ans = true;
    int count = 0;

    cin >> s;
    if(s[0] != 'A') ans = false;
    for(int i = 2; i < s.length()-1; i ++ ){
        if(s[i] == 'C') count ++;
    }
    if(count != 1) ans = false;
    for(int i = 0; i < s.length(); i ++){
        if(s[i] != 'A' && s[i] != 'C'){
            if(!islower(s[i])) ans = false;
        }
    }

    cout << ((ans)?"AC":"WA");
    return 0;
}

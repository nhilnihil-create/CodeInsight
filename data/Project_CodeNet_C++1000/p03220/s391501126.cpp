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
    int n;
    float t,a;
    float Min = 10000000;
    float ans = 0;
    float tmp;

    cin >> n >> t >> a;

    for(int i = 0; i < n; i ++){
        cin >> tmp;
        if(Min > abs(a-(t-tmp*0.006f))){
            Min = abs(a-(t-tmp*0.006f));
            ans = i;
        }
    }

    cout << ans+1;
    return 0;
}










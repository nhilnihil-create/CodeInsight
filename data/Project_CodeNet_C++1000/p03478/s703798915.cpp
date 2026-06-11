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


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
\
#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;


int main() {
    int n,a,b;
    int ans = 0;
    cin >> n >> a >> b;
    for(int i = 1; i <=n; i ++){
        string tmp = to_string(i);
        int val = 0;
        for(int j = 0; j < tmp.length(); j ++){
            val += (int)(tmp[j] - '0');
        }
        if(val >= a && val <= b) ans += i;
    }
    cout << ans;
}






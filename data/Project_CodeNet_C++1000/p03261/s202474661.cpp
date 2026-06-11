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
    int n;
    bool ans = true;
    string prev,cur;
    map<string,bool> mp;
    cin >> n;

    REP(i,n){
        cin >>cur;
        if(i == 0) {
            prev = cur;
            mp[cur] = true;
        } else{
            if((prev[prev.length()-1] != cur[0])||(mp.count(cur) != 0)){
                ans = false;
                break;
            }else{
                prev = cur;
                mp[cur] = true;
            }
        }
    }
    cout << ((ans)?"Yes":"No");
}






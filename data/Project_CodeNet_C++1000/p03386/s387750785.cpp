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
    int a,b,k;
    cin >> a >> b >> k;
    if((b-a+1) <= 2*k){
        for(int i = a; i <= b; i ++){
            cout << i << endl;
        }
    }else{
        for(int i = a; i <= a+k-1; i ++){
            cout << i << endl;
        }
        for(int i = b-k+1; i <= b; i ++){
            cout << i << endl;
        }
    }

}






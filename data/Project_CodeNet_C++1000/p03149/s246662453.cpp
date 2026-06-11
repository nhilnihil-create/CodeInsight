#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    int N[5], i, a;

    for(i=1; i<=4; i++){
        cin >> N[i];
    }

    sort(N+1, N+5);

    a = N[1]*1000+N[2]*100+N[3]*10+N[4];

    if(a==1479){
        cout << "YES" << endl;
    }

    else{
        cout << "NO" << endl;
    }

    return 0;
}
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, M;

    cin >> N >> M;

    if(N==1 && M==1){
        cout << 1 << endl;
    }

    else if(N>=2 && M>=2){
        cout << (N-2)*(M-2) << endl;
    }

    else{
        cout << N*M-2 << endl;
    }

    return 0;
}
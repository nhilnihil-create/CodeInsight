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
    long long A, B, C, la, lb, lc, K, i;

    cin >> A >> B >> C >> K;

    if(abs(A-B) > 1e18){
        cout << "Unfair" << endl;
    }

    else{
        if(K%2 == 0){
            cout << A-B << endl;
        }

        else{
            cout << B-A << endl;
        }
    }
 
    return 0;
}
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
    long long A, B, C, ans=0;

    cin >> A >> B >> C;

    if(C < A+B+1){
        cout << B+C << endl;
    }

    else{ // C >= A+B+1
        cout << B+(A+B+1) << endl;
    }
 
    return 0;
}
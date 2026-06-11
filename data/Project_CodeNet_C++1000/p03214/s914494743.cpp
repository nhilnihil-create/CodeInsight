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
    int N, i, a[101];
    double ave=0, min=1000;

    cin >> N;

    for(i=0; i<=N-1; i++){
        cin >> a[i];
        ave += a[i];
    }

    ave /= (double)N;

    for(i=0; i<=N-1; i++){
        chmin(min, fabs(ave-a[i]));
    }

    for(i=0; i<=N-1; i++){
        if(fabs(ave-a[i])==min){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
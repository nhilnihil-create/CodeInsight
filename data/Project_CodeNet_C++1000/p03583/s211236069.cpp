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
#include <stack>
#include <queue>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using ld = long double;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, j, x, y, z, a, b;

    cin >> N;

    for(i=1; i<=3500; i++){
        for(j=1; j<=3500; j++){
            a = N*i*j;
            b = 4*i*j - N*i - N*j;

            if(b>0 && a%b==0){
                x = i;
                y = j;
                z = a/b;
            }
        }
    }

    cout << x << " " << y << " " << z << endl;

    return 0;
}
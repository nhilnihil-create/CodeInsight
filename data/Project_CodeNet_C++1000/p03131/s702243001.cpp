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
    ll K, A, B, num=1, i;

    cin >> K >> A >> B;

    i = 1;
    while(i<=K){
        if(num>=A && i<=K-1 && B-A>=3){
            num += (B-A);
            i += 2;
        }
        else{
            num++;
            i++;
        }
    }

    cout << num << endl;
    
    return 0;
}
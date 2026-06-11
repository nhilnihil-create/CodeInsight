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
    ll A, B, K, i;

    cin >> A >> B >> K;

    for(i=1; i<=K; i++){
        if(i%2==1){
            if(A%2==1) A--;

            A -= A/2; B += A;      
        }

        else{
            if(B%2==1) B--;

            B -= B/2; A += B;
        }
    }

    cout << A << " " << B << endl;

    return 0;
}
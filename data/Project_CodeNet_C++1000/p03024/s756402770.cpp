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
    string S;
    int count=0, i, k;

    cin >> S;
    
    k = S.size();

    for(i=0; i<k; i++){
        if(S[i] == 'o'){
            count++;
        }
    }

    if(count+(15-k) >= 8){
        cout << "YES" << endl;
    }

    else{
        cout << "NO" << endl;
    }

    return 0;
}
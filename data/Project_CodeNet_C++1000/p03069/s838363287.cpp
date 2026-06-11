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
    ll N, i, l_white=0, r_black=0, ans=INF;
    string S;

    cin >> N >> S;

    for(i=0; i<N; i++){
        if(S[i]=='#'){
            r_black++;
        }
    }

    chmin(ans, N-(l_white+r_black));

    for(i=0; i<N; i++){
        if(S[i]=='#'){
            r_black--;
        }
        else{
            l_white++;
        }

        chmin(ans, N-(l_white+r_black));
    }

    cout << ans << endl;

    return 0;
}
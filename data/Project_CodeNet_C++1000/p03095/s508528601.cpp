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
    string S;
    ll N, i, al[30], ans=1;

    cin >> N >> S;

    for(i=0; i<26; i++){
        al[i] = 0;
    }

    for(i=0; i<N; i++){
        al[S[i]-'a']++;
    }

    for(i=0; i<26; i++){
        ans *= (al[i]+1);

        ans = ans % div1;
    }

    ans--;

    ans = ans % div1;
    
    cout << ans << endl;

    return 0;
}
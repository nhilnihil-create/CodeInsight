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
    string s;
    ll i, j, judge=1, ans=0;

    cin >> s;

    i = 0;
    j = s.size()-1;

    while(i < j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else if(s[i]=='x'){
            ans++;
            i++;
        }
        else if(s[j]=='x'){
            ans++;
            j--;
        }
        else{
            judge = 0;
            break;
        }
    }

    if(judge==1) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
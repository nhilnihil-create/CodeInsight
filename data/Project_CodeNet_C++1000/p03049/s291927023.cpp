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
    ll N, i, j, a=0, ab=0, b=0, ab_d=0, ans;
    string s[10001];

    cin >> N;

    for(i=1; i<=N; i++){
        cin >> s[i];
    }

    for(i=1; i<=N; i++){
        if(s[i][0]=='B' && s[i][s[i].size()-1]=='A') ab_d++;
        else if(s[i][0]=='B') b++;
        else if(s[i][s[i].size()-1]=='A') a++;
        
        if(s[i].size() >= 2){
            for(j=0; j<s[i].size()-1; j++){
                if(s[i][j]=='A' && s[i][j+1]=='B'){
                    ab++;
                }
            }
        }
    }

    ans = ab;

    if(ab_d == 0){
        ans += min(a,b);
    }

    else{
        if(a+b>0){
            ans += ab_d+min(a,b);
        }

        else{
            ans += ab_d-1;
        }
    }

    cout << ans << endl;

    return 0;
}
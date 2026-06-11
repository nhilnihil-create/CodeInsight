#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
#include <iomanip>  // std::setprecision()
#include <set>

using namespace std;
using ll = long long;
#define rep(i,a,b) for(ll i=(a); i<(b); i++)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define pai 3.14159265358979323846
ll gcd(ll a, ll b){if (a%b == 0)  return(b);else  return(gcd(b, a%b));}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
/* map<string,int> */
/* 大文字を小文字に変換 tolower*/
/* 小文字を大文字に変換 toupper*/
/* 辞書順 next_permutation(a.begin(),a.end()) */
 
int main() {
    string s,t;
    cin >> s >>t;
    if (s == t) {
        cout << "Yes" << endl;
        return 0;
    }
    string n;
    n = s;
    rep(j,0,s.size()+1) {
        rep(i,0,s.size()) {
            if (i ==0) {
                n[0] = s[s.size()-1];
            } else {
                n[i] = s[i-1];
            }
        }
        if (n == t)  {
            cout << "Yes" <<endl;
            return 0;
        }
        s = n;
    }
    cout << "No" << endl;
}
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
    int n,m;
    cin >> n >> m;
    int X,Y;
    cin >> X >> Y;
    vector <int> x(n);
    vector <int> y(m);
    rep(i,0,n) {
        cin >> x[i];
    }
    rep(i,0,m) {
        cin >> y[i];
    }
    rep(i,X+1,Y+1) {
        bool flag = true;
        rep (j,0,n) {
            if (x[j] >= i) {
                flag = false;
            }
        }
        rep (j,0,m) {
            if (y[j] < i) {
                flag = false;
            }
        }
        if (flag) {
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}
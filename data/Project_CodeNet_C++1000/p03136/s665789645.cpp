#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
#include <iomanip>  // std::setprecision()
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=(a); i<(b); i++)
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
    int n;
    cin >> n ;
    vector <int> a(n);
    int ma = 0;
    rep(i,0,n) {
        cin >>a[i];
        ma = max (ma,a[i]);
    }
    int count =0;
    rep(i,0,n) {
        if(a[i] == ma) count++;
    }
    int b =0;
    rep(i,0,n) {
        if (!(a[i] == ma)) {
            b += a[i];
        }
    }
    b += ma * (count-1);
    if (ma < b) {
        yes
    } else {
        no
    }
}
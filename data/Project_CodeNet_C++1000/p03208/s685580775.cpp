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
ll gcd(ll a, ll b){if (a%b == 0)  return(b);else  return(gcd(b, a%b));}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
/* map<string,int> */
/* 大文字を小文字に変換 tolower*/
/* 小文字を大文字に変換 toupper*/
/* 辞書順 next_permutation(a.begin(),a.end()) */
 
int main() {
    int n,k;
    cin >> n >>k;
    vector <ll> h(n);
    rep(i,0,n) {cin >> h[i];}
    sort(h.begin(), h.end());
    ll mi = 1000000000;
    rep(i,0,n-k+1) {
        mi = min(mi, h[i+k-1]-h[i]);
    }
    cout << mi <<endl;
}
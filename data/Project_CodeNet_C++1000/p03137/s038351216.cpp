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
// setprecision(n)
/* map<string,int> */
/* 大文字を小文字に変換 tolower*/
/* 小文字を大文字に変換 toupper*/
/* 辞書順 next_permutation(a.begin(),a.end()) */
int main() {
    int n,m;
    cin >> n >> m;
    vector <int> x(m);
    rep(i,0,m){cin >> x[i];}
    sort(x.begin(),x.end());
    vector <int> a(m-1);
    rep(i,0,m-1) {
        a[i] = x[i+1] - x[i];
    }
    sort(a.begin(),a.end());
    int ans = 0;
    rep (i,0,m-1-n+1) {
        ans += a[i];
    }
    cout << ans << endl;


}
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
    ll n ,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector <ll> a(n, 0);
    ll count = 0;
    for (ll i=0; i < n-1; i++) {
        a[i] = count;
        if (s[i] == 'A' && s[i+1] == 'C') {
            count++;
        }
    }
    a[n-1] = count;
    ll l,r;
    vector <ll > ans(q);
    for(ll i =0;i <q; i++) {
        cin >> l >> r;
        ans[i] = a[r-1] - a[l-1];
    }
    for(ll i =0;i <q; i++) {
        cout << ans[i] << endl;
    }
}
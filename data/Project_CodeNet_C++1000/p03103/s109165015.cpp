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
    int n,m;
    cin >> n >> m;
    multimap <ll, int> ab;
    rep(i,0,n) {
        ll a;
        int b;
        cin >> a >> b; 
        ab.insert(make_pair(a,b));
    }
    ll ans =0;
    for(auto i = ab.begin(); i!= ab.end(); i++) {
        if (i->second >= m) {
            ans += m * i->first;
            break;
        } else {
            ans += i->second * i->first;
            m -= i->second;
        }
    }
    cout << ans << endl;
}
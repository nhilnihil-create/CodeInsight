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
    vector <vector <int>> s(m);
    rep (i,0,m) {
        int k;
        cin >> k;
        rep(j,0,k) {
            int a;
            cin >> a;
            a--;
            s[i].push_back(a);
        }

    }
    vector <int> p(m);
    rep (i,0,m) {
        cin >> p[i];
    }
    ll ans = 0;
    for (int bit = 0; bit < (1<< n); bit++) {
        bool flag = true;
        for(int i = 0; i <m; i++) {
            int count = 0;
            for (auto v : s[i]) {
                if (bit & (1 << v)) count++;
            }
            if (count % 2 != p[i]) flag = false;
        }
        if (flag) ans++;

    }
    cout << ans << endl;
}
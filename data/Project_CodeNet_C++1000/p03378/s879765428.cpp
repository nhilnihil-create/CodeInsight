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
void printVec(std::vector<char> &vec) {
  std::cout << "";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
 
int main() {
    int n,m,x;
    cin >> n >> m >>x;
    int t = x;
    vector <int> a(m);
    rep(i,0,m) {
        cin >> a[i];
    }
    int sum = 0;
    int mi = 0;
    while (x != n) {
        bool flag = false;
        x++;
        rep (i,0,m) {
            if (a[i] == x) {
                flag = true;
            }
        }
        if (flag) sum++;
    }
    mi = sum;
    sum = 0;
    x = t;
    while (x != 0) {
        bool flag = false;
        x--;
        rep (i,0,m) {
            if (a[i] == x) {
                flag = true;
            }
        }
        if (flag) sum++;
    }
    mi = min(mi,sum);
    cout << mi << endl;
}
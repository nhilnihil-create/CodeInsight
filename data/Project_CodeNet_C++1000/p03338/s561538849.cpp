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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <char> a(n);
    int ma =0;
    rep(i,0,n-1) {
        // a = unique(s.begin()+i+1, s.end()) ;
        rep(j,i+1,n) {
            a.push_back(s[j]);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int count = 0;
        for(int j =0;j <a.size();j++) {
            rep(k,0,i+1) {
                if (a[j] == s[k]) {
                    count++;
                    break;
                }
            }
        }
        ma = max(ma, count);
        a.clear();
    }
    cout << ma << endl;
}
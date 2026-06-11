
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
 
int main () {
    int n,m;
    cin >> n >>m;
    vector <bool> a(m,false);
    vector <int>b(n);
    vector <vector <int>> c(n);
    for(int i =0;i<n;i++) {
        cin >> b[i];
        for(int j = 0;j<b[i]; j++) {
            int tmp;
            cin >> tmp;
            c[i].push_back(tmp);
        }
    }
    for(int i =1; i<m+1;i++) {
        bool flag1 = true;
        for(int j =0;j<n;j++) {
            bool flag2 = false;
            for(int k =0; k < b[j];k++) {
                if (i == c[j][k]){
                    flag2 = true;
                }
            }
            if (flag2 == false) {
                flag1 = false;
                break;
            }
        }
        if (flag1) {
            a[i] = true;
        }
    }
    int count =0;
    for(int i =1;i <= m; i++) {
       if (a[i]) {
           count++;

       }
    }
    cout << count << endl;
}
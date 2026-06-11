#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

#define ll long long
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){ return (a % b)? gcd(b, a%b) : b; }
template<typename T> T lcm(T a, T b){ return a * b / gcd(a, b); }

int main(void){
    int n, m, c;
    cin >> n >> m >> c;
    int b[m];
    REP(i,m) cin >> b[i];
    int a[n][m];
    REP(i,n) REP(j,m) cin >> a[i][j];

    int ctr = 0;
    REP(i,n){
        ll tmp = 0;
        REP(k,m){
            tmp += a[i][k] * b[k];
        }
        if(tmp + c >0) ctr++;
    }
    cout << ctr << endl;
    
    return 0;
}
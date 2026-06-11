#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <set>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

int main(void){
    int n;
    cin >> n;
    int a[n];
    REP(i,n) cin >> a[i];

    int ctr = 0;
    while(1){
        bool exist = true;
        REP(i,n){
            if(a[i] % 2 == 1){
                exist = false;
            }
        }
        if(exist){
            REP(i,n) a[i] /= 2;
            ctr++;
        } else break;
    }
    cout << ctr << endl;
    return 0;
}
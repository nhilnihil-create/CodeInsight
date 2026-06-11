#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

void solve_79B(){
    ll n;
    cin >> n;

    ll a = 2, b = 1, c;
    if(n == 1) cout << 1 << endl;
    else{
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
}

int main(void){
    solve_79B();
    
    return 0;
}
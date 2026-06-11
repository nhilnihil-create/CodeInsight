#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;

int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}

ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    a / gcd(a,b) * b;
}
const ll mod = 1e9 + 7;
const ll INF = 1e9 + 7;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


/////////////////////////////////////////////////////////////////////////////////////////

int main(){
    int n,k;
    cin >> n >> k;
    ll a = n / k,b = 2*n / k;
    if (k & 2 != 0){
        cout << a * a * a << endl;
    }
    else {
        cout << a*a*a + (b-a)*(b-a)*(b-a) << endl;
    }   
}
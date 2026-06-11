#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const ll mod = 1e9 + 7;
 
int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}
 
ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

bool is_prime(long long N){
    if (N == 1) return false;
    for (long long i = 2;i * i <= N;i++){
        if (N % i == 0) return false;
    }
    return true;
}
 
ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}
 
double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
 
///////////////////////////////////////////////////////////////////////////////////

int main(){
    int n;
    cin >> n;
    bool ok = true;
    vector<int> t(n), x(n), y(n);
    for (int i = 0;i < n;i++){
        cin >> t[i] >> x[i] >> y[i];
    }
    
    if((t[0] - x[0] - y[0]) %2 != 0 || t[0] < x[0] + y[0]){
        cout << "No" << endl;
        return 0;
    }
    int D, T;
    for (int i = 1;i < n;i++){
        D = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        T = t[i] - t[i-1];

        if ((T-D)%2 != 0 || D > T){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
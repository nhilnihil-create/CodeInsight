#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    int a[n+2];
    a[0] = 0;
    int total = abs(a[0]);
    for(int i = 1;i < n+1;i++){
        cin >> a[i];
        total += abs(a[i]-a[i-1]);
    }
    total += abs(a[n]);
    a[n+1] = 0;
    
    for(int i = 1;i < n+1;i++){
       cout << total -  abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]-a[i-1]) << endl;
    }
}


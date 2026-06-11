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
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = 0;
    int sum = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        sum += abs(a[i] - a[i-1]);
    }
    
    int ans;
    for (int i = 1;i <= n;i++){
        if (i == 1){
            ans = sum - abs(a[i]) - abs(a[1] - a[2]) + abs(a[2]) + abs(a[n]);
        }
        else if (i == n){
            ans = sum - abs(a[n-1] - a[n]) + abs(a[n-1]);
        }
        else{
            ans = sum - abs(a[i] - a[i-1]) - abs(a[i] - a[i+1]) + abs(a[i-1] - a[i+1]) + abs(a[n]);
        }

        cout << ans << endl;
    }

    return 0;
}
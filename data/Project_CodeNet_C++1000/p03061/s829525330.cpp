#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int NMAX = 2000;
const int MOD = 1000000007;

int gcd(int a, int b){
    
    if(a==0)return b;
    if(b==0)return a;
    
    if(a<b)
        swap(a,b);
    
    while(a%b!=0){
        a %= b;
        swap(a,b);
    }
    return b;
}

int main() {
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    
    vector<int> lg(n,0), rg(n,0);
    
    for(int i=1; i<n; i++){
        lg[i] = gcd(lg[i-1], a[i-1]);
    }
    for(int i=n-2; i>=0; i--){
        rg[i] = gcd(rg[i+1], a[i+1]);
    }
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        ans = max(ans, gcd(lg[i], rg[i]));
    }
    
    cout << ans << endl;
    
    return 0;
}
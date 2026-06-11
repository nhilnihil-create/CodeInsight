#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    int n; cin >> n;
    int ans=0;
    if(n>=105) ans++;
    if(n>=135) ans++;
    if(n>=165) ans++;
    if(n>=189) ans++;
    if(n>=195) ans++;
    cout << ans << endl;
}
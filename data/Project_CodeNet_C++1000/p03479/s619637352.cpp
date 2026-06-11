#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007
typedef pair<ll,ll> P;

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}


int main(){
    ll x,y,ans=0;
    cin >> x >> y;
    while(x<=y){
        ans++;
        x*=2;
    }
    cout << ans << endl;
    
    return 0;
}










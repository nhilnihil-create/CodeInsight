#include<bits/stdc++.h>
#define ll long long 
#define P pair<ll ,ll>
using namespace std;

ll gcd(ll a,ll b){
    if(a<b)return gcd(b,a);
    if(a%b==0)return b;
    return gcd(b ,a%b);
}
int main(){
    int n;cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        ans += a-1;
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}


int main(void){
    ll n, m;
    cin>>n>>m;
    string s, t;
    cin>>s>>t;
    bool ok = true;
    rep(i, n){
        if(((ll)i*m)%n == 0) {
            ll j = ((ll)i*m)/n;
            if(s[(int)i] != t[(int)j]) {
                ok = false;
                break;
            }
        }
    }
    if(ok){
        cout<<lcm(n, m)<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
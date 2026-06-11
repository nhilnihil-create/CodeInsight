#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
    ll a,b;
    cin >> a >> b;

    ll m,n;
    if(a==0){
        m=a;
    }else{
        a--;
        ll ad = a/2;
        if(ad%2==0){
            ad = 0;
        }else{
            ad = 1;
        }
        if(a%2==0){
            m = a^ad;
        }else{
            m = 1^ad;
        }
    }


    ll bd = b/2;
    if(bd%2==0){
        bd = 0;
    }else{
        bd = 1;
    }
    if(b%2==0){
        n = b^bd;
    }else{
        n = 1^bd;
    }

    ll ans = m^n;

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
ll XOR(ll n){
    if(n < 0) return 0;
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else if(n % 4 == 3) return 0;
}
int main(){
    Hello
    ll a, b;
    cin >> a >> b;
    ll x1 = XOR(a - 1), x2 = XOR(b);
    cout << (x1 ^ x2);
    return 0;
}
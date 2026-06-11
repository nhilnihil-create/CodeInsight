#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) return gcd(b,a);
    ll r;
    while(r=a%b){
        a = b; b = r;
    }
    return b;
}

int main(){
    int N;
    cin >> N;
    cout << ( N <= 999 ? "ABC" : "ABD") << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    while(b != 0){
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main(){
    int n;
    cin >> n;
    vector<ll> monster(n);
    for(int i=0;i<n;i++) cin >> monster.at(i);
    ll g = gcd(monster.at(0),monster.at(1));
    for(int i=2;i<n;i++){
        g = gcd(g,monster.at(i));
    }
    cout << g << endl;
}
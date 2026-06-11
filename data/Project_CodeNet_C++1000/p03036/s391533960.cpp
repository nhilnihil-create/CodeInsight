#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll N = 3e5 + 5; 
const ll MAX = 3e5 + 5; 
const ll M = 1e6 + 5;

int main(){
    ll r,d,x;
    ll sum = 0;
    cin>>r>>d>>x;

    for (int i = 0; i < 10; i++){
        x =  r * x  - d;
        
        cout << x << endl;
    }
}
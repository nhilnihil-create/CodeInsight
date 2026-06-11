#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    ll n, m;    cin >> n >> m;

    //cout << m << ' ' << (n*(n+1)/2) << endl;
    for(ll i=m/n; 1<=i; i--){
        if(m%i==0){
            cout << i << endl;
            return 0;
        }
    }
}
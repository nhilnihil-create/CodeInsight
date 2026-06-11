#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    ll a, b; cin >> a >> b;
    ll c = 0;
    if(a % 2 == 0 && b % 2 == 0){
        c = (b - a) / 2;
        if(c % 2 == 0){
            cout << (0 ^ b) << endl;
        }else{
            cout << (1 ^ b) << endl;
        }
    }else if(a % 2 == 0){
        c = (b - a + 1) / 2;
        if(c % 2 == 0){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
    }else if(b % 2 == 0){
        c = (b - (a + 1)) / 2;
        if(c % 2 == 0){
            cout << (a ^ 0 ^ b) << endl;
        }else{
            cout << (a ^ 1 ^ b) << endl;
        }
    }else{
        c = (b - a) / 2;
        if(c % 2 == 0){
            cout << (a ^ 0) << endl;
        }else{
            cout << (a ^ 1) << endl;
        }
    }
}

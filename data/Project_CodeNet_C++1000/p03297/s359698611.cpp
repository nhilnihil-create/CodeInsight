#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool solve(ll A, ll B, ll C, ll D){
    if(A < B) return false;
    if(D < B) return false; 
    if(B <= C) return true;
    ll g = __gcd(B, D);
    C -= A - 1, B -= A;
    return C / g == B / g;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << (solve(A, B, C, D) ? "Yes" : "No") << endl;
    }
    return 0;
}
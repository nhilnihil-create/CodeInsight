#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// b-a <=2 いみなし -> k+1
// k >=2 & a >= s -> 
int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll s = 1;
    if(b-a <= 2) {
        cout << k+1 << endl;
        return 0;
    }
    
    rep(i,k) {
        if(s < a) { s++; continue;}
        else if(k-i>=2){
            s-=a;
            s+=b;
            i++;
            continue;
        }
        else s++;

    }   
    cout << s << endl;
    return 0;
}
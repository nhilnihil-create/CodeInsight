#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
/*
bool ok (int x){
    bool ok = true;
    for(int i = 2; i*i <= x; ++i){
        if(x%i==0) {ok = false; break;}
    }
    return ok;
}
*/

int main() {
    int q;
    int max = 10101010;
    cin >> q;
    // エラトステネスのふるい
    vector<int> prime(max, 1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i < max; i++){
        if(!prime[i]) continue;
        for(int j = i*2; j < max; j+=i){
            prime[j]=0;
        }
    }

    vector<int> x(max, 0);
    rep(i,max){
        if(i%2==0) continue;
        if(prime[i] && prime[(i+1)/2]) x[i]=1;
    }

    vector<int> y(max+1, 0);
    rep(i,max){
        y[i+1] = y[i] + x[i];
    }

    rep(i,q) {
        int l, r;
        cin >> l >> r;
        r++;
        cout << y[r]-y[l] << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x) cin >> a.at(i);
    rep(i,y) cin >> b.at(i);
    rep(i,z) cin >> c.at(i);
    vector<ll> ab,abc;
    rep(i,x){
        rep(j,y){
            ab.push_back(a.at(i)+b.at(j));
        }
    }
    sort(ab.rbegin(),ab.rend());

    rep(i,min(k,x*y)){
        rep(j,z){
            abc.push_back(ab.at(i)+c.at(j));
        }
    
    }
    sort(abc.rbegin(),abc.rend());
    rep(i,k){
        cout << abc.at(i) << endl;
    }
    return 0;
}
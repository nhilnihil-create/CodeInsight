#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

vi p;
vector<bool> bp(55555+1,true);

void sieve(ll n){
    if(n<2)return;
    for(ll i=2; i<=n; i++){
        if(!bp[i])continue;
        p.push_back(i);
        for(ll j=i*i; j<=n; j+=i){
            if(bp[j]) bp[j] = false;
        }
    }
    return;
}

int main(){
    sieve(55555);
    int n; cin >> n;
    
    vi p1;
    rep(i,p.size()){
        if(p[i]%5==1)p1.push_back(p[i]);
    }
    
    rep(i,n){
        cout << p1[i];
        if(i!=n-1) cout << " ";
        else cout << endl;
    }
    return 0;
}
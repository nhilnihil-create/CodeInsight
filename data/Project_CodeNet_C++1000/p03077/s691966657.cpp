#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<int>;
using P  = pair<ll,ll>;

int main(){
    ll n;cin>>n;
    ll amin = 1001001001001001, a;
    rep(i,5){
        cin>>a;
        amin = min(amin, a);
    }
    
    cout << 4LL + (n+amin-1)/amin << endl;
    
    return 0;
}

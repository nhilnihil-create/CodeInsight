#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    ll n,k; cin>>n>>k;
    ll x=0,y=0; 
    rep(i,1,n+1){
        if(i%k==0) x++;
        if(i%k==k/2) y++;
    }
    if(k%2==0){
        cout<<x*x*x+y*y*y<<endl;
    }else{
        cout<<x*x*x<<endl;
    }

}
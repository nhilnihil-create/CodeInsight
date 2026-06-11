#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int n;
    cin>>n;
    map<ll,int> d;
    for(int i=0; i<n; i++){
        ll D;
        cin>>D;
        d[D]++;
    }
    int m;
    cin>>m;
    bool ok=true;
    for(int i=0; i<m; i++){
        ll t;
        cin>>t;
        if(d[t]==0) ok=false;
        else d[t]--;
    }
    cout<<(ok?"YES":"NO")<<endl;

}
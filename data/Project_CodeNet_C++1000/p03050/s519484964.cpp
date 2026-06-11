#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    ll n;
    cin >> n;

    vector<ll> p;

    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            p.push_back(i);
            if(i*i!=n) p.push_back(n/i);
        }
    }

    ll sum=0;
    rep(i,p.size()){
        // cout << p[i] << ' ' << n/p[i] << ' ';
        if(p[i]-1>n/p[i]) sum+=(p[i]-1);
        // cout << sum << endl;
    }

    cout << sum << endl;
    
    return 0;
}
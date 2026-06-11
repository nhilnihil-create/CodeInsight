#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll a,b,k; cin>>a>>b>>k;
    rep(i,k){
        if(i%2){
            if(b%2) b--;
            a += b/2;
            b/=2;
        }else{
            if(a%2) a--;
            b += a/2;
            a/=2;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
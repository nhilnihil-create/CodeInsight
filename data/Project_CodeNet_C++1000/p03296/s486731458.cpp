#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }
    ll cnt=0;
    rep(i,n-1){
        if(a[i]==a[i+1]){
            cnt++;
            a[i+1]=-1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
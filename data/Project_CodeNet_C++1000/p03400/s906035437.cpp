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
    ll n,d,x; cin>>n>>d>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll sum=x;
    rep(i,n){
        for(int day=1;day<=d;day+=a[i]){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
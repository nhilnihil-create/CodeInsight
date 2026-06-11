#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;


int main() {
    int n;
    cin>>n;
    vector<pair<ll,int>> v(n);
    vector<ll> a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        v[i]={a[i]+b[i],i};
    }

    sort(all(v));
    reverse(all(v));
    ll st=0,sa=0;
    rep(i,n){
        if(i%2==0) st+=a[v[i].second];
        else sa+=b[v[i].second];
    }

    //cout<<st<<" "<<sa<<endl;
    cout<<st-sa<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

vector<ll> v;
ll dsum(ll n){
    ll sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    int k;
    cin>>k;
    int cnt=0;
    FOR(i,1,10) v.pb(i);
    ll p=100000000000;
    double mn=1000100010001000100;
    while(p>0){
    for(ll i=9999;i>=1000;--i){
        ll t=i*p+p-1;
        double ans=(double)t/dsum(t);
        if(ans<mn){
            mn=ans;
            v.pb(i*p+p-1);
        }
    }
    p/=10;
    }
    for(ll i=1000;i>=1;--i){
        ll t=i;
        double ans=(double)t/dsum(t);
        if(ans<mn){
            mn=ans;
            v.pb(t);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto it:v){
        cout<<it<<endl;
        ++cnt;
        if(cnt==k) break;
    }
    return 0;
}
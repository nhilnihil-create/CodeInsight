#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];

    int ans=0;
    ll sum=0;
    vector<ll> v;
    rep(i,n){
        if(a[i]>b[i]){
            v.push_back(a[i]-b[i]);
        }
        else if(a[i]<b[i]){
            ans++;
            sum+=b[i]-a[i];
        }
    }

    if(sum==0){
        cout<<0<<endl;
        return 0;
    }
    
    sort(all(v));
    reverse(all(v));
    rep(i,v.size()){
        sum-=v[i];
        ans++;
        if(sum<0){
            cout<<ans<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll x = a[n-1];
    ll ans = 0;
    ll m = x;
    for(int i=0;i<n;i++){
        ll dif = min(abs(a[i] - x/2), abs(a[i] - (x -x/2)));
        if(dif<m){
            ans = a[i];
        }
        m = dif;
    }
    cout<<x<<" "<<ans<<endl;
}

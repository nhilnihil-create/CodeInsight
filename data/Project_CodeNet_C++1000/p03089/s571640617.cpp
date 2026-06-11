#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;



int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    vector<ll> ans;
    while(!a.empty()){
        bool flag=false;
        ll m=a.size();
        for(ll i=m-1;i>=0;i--){
            if(a[i]==i+1){
                flag=true;
                ans.push_back(i+1);
                a.erase(a.begin()+i);
                break;
            }
        }
        if(!flag){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    for(ll i=0;i<n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}  

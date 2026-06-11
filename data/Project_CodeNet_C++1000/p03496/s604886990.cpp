#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr long long inf = 1000006;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<pii> ans;
    ll mx = 0 , mn = inf;
    int mxi,mni;
    for(int i=0;i<n;i++){
        if(a[i] > mx){
            mx = a[i];
            mxi = i;
        }
        if(a[i] < mn){
            mn = a[i];
            mni = i;
        }
    }

    if(abs(mx) > abs(mn)){
        for(int i=0;i<n;i++){
            if(mxi == i) continue;
            ans.emplace_back(mxi,i);
        }
        for(int i=0;i<n-1;i++){
            ans.emplace_back(i,i+1);
        }
    }else{
        for(int i=0;i<n;i++){
            if(mni == i) continue;
            ans.emplace_back(mni,i);
        }
        for(int i=n-1;i>0;i--){
            ans.emplace_back(i,i-1);
        }
    }
    cout << ans.size() << endl;
    for(pii p : ans){
        cout << p.first+1 << " " << p.second+1 << endl;
    }
}

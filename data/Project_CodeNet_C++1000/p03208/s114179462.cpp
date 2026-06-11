#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
    ll n, k;
    cin>>n>>k;
    vector<int> h(n);
    rep(i,n){
        cin>>h[i];
    }
    sort(h.begin(), h.end());
    int nagasa;
    vector<int> ans(n-k+1);
    rep(i,n-k+1){
        nagasa= h[i+k-1]-h[i];
       ans[i]=nagasa;
    }
    sort(ans.begin(), ans.end());
    cout << ans.at(0) << endl;
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    ll x,y;
    cin>>x>>y;
    vector<ll> ans;
    ans.push_back(x);
    while(ans[ans.size()-1]<=y) {
        ans.push_back(ans[ans.size()-1]*2);
    }
    cout<<ans.size()-1<<endl;
}

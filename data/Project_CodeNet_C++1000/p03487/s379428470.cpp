#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    ll ans=0;
    cin>>n;
    map<int,int> mp;
    rep(i,n) {
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    for (auto v : mp) {
        if (v.first<v.second) {
            ans+=v.second-v.first;
        } else if(v.first>v.second) {
            ans+=v.second;
        }
    }
    cout<<ans<<endl;
}

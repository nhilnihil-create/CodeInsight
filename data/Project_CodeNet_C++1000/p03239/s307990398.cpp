#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,T,mini=10000;
    cin>>n>>T;
    vector<int> c(n),t(n);
    rep(i,n) cin>>c[i]>>t[i];
    rep(i,n) {
        if (t[i]<=T) {
            mini=min(mini,c[i]);
        }
    }
    if (mini==10000) cout<<"TLE"<<endl;
    else cout<<mini<<endl;
}

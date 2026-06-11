#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,ans=100000000,res;
    string s;
    cin>>n>>s;
    vector<int> e(n+1,0),w(n+1,0);
    rep(i,n) {
        if (s[i]=='E') {
            e[i+1]=e[i]+1;
            w[i+1]=w[i];
        } else {
            e[i+1]=e[i];
            w[i+1]=w[i]+1;
        }   
    }
    rep(i,n) {
        res=e[n]-e[i+1];
        ans=min(ans,res+w[i]);
    }
    cout<<ans<<endl;
}

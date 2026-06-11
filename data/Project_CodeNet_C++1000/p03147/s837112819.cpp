#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n) cin>>h[i];
    int ans=h[0];
    for (int i=1; i<n; i++) {
        if (h[i-1]<h[i]) ans+=h[i]-h[i-1];
    }
    cout<<ans<<endl;
}

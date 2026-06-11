#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int k;
    ll ans=0;
    vector<int> a(3);
    cin>>a[0]>>a[1]>>a[2]>>k;
    sort(a.begin(),a.end());
    rep(i,k) a[2]*=2;
    rep(i,3) ans+=a[i];
    cout<<ans<<endl;
}

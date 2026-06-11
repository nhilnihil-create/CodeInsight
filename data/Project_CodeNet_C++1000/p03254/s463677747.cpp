#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,x,ans=0;
    cin>>n>>x;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    rep(i,n) {
        if (i!=n-1&&a[i]<=x) {
            ans++;
            x-=a[i];
        } else if(i==n-1&&a[i]==x) {
            ans++;
        }
    }
    cout<<ans<<endl;
}

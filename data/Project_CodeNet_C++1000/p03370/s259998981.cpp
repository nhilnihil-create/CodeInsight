#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,x,sum=0,ans=0;
    cin>>n>>x;
    vector<int> m(n);
    rep(i,n) {
        cin>>m[i];
        sum+=m[i];
        ans++;
    }
    sort(m.begin(),m.end());
    while(sum<=x) {
        sum+=m[0];
        ans++;
    }
    if (sum>x) ans--;
    cout<<ans<<endl;
}

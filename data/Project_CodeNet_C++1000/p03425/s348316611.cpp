#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    cin>>n;
    string s;
    ll ans=0;
    vector<ll> a(5,0);
    rep(i,n) {
        cin>>s;
        if (s[0]=='M') a[0]++;
        else if(s[0]=='A') a[1]++;
        else if(s[0]=='R') a[2]++;
        else if(s[0]=='C') a[3]++;
        else if(s[0]=='H') a[4]++;
    }
    for (int i=0; i<3; i++) {
        for (int j=i+1; j<4; j++) {
            for (int k=j+1; k<5; k++) {
                ans+=a[i]*a[j]*a[k];
            }
        }
    }
    cout<<ans<<endl;
}

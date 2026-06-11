#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s,res,ans;
    cin>>s;
    int n=s.size();
    int small=0,c=0;
    rep(i,n) {
        if (s[i]>='a'&&s[i]<='z') small++;
    }
    if (s[0]=='A'&&small==n-2) {
        res=s.substr(2,(n-3));
        rep(i,res.size()) {
            if (res[i]=='C') c++;
        }
        if (c==1) ans="AC";
        else ans="WA";
    } else {
        ans="WA";
    }
    cout<<ans<<endl;
}   

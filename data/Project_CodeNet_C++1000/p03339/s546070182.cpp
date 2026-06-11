#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ed(n+1);
    rep(i,n) {
        if (s[i]=='E') ed[i+1]=ed[i]+1;
        else ed[i+1]=ed[i];
    }
    int ans=n;
    rep(i,n) {
        int tans=i-(ed[i]-ed[0])+ed[n]-ed[i+1];
        ans=min(ans,tans);
    }
    cout << ans << endl;
}
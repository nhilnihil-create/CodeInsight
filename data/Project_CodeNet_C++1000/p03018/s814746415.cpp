#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
const int MOD=1e9+7;

int main() {
    string s;
    cin >> s;
    int n=s.size();
    ll ans=0,acnt=0;    
    rep(i,n-2) {
        if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') {
            ans+=acnt+1;
            s[i+2]='A';
            ++i;
        }
        else if (s[i]=='A') ++acnt;
        else acnt=0;
    }
    cout << ans << endl;
}
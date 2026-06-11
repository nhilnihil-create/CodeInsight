#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int MAX=1e5+10;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string t="PWGY";
    vector<int> cnt(4);
    rep(i,n) {
        char c;
        cin >> c;
        rep(i,4) {
            if (c==t[i]) cnt[i]=1;
        }
    } 
    int ans=0;
    rep(i,4) {
        if (cnt[i]==1) ++ans;
    }
    if (ans==3) cout << "Three" << endl;
    else cout << "Four" << endl;
     
    return 0;   
}
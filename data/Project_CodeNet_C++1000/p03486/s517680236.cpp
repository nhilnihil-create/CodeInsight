#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    string s,t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<>());
    int n=min(s.size(),t.size());
    int flag=-1;
    rep(i,n) {
        if (s[i]<t[i]) {
            flag=1;
            break;
        } else if (s[i]>t[i]) {
            flag=0;
            break;
        }
    }
    if (flag==-1) {
        if (s.size()<t.size()) flag=1;
        else flag=0;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
   
    return 0;  
}
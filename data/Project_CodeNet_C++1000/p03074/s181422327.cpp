#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt=1;
    char prev=s[0];
    vector<int> c;
    if (s[0]=='0') c.push_back(0);
    repr(i,1,n) {
        if (s[i]!=prev) {
            c.push_back(cnt);
            cnt=1;
        } else ++cnt;
        prev=s[i];
    }
    c.push_back(cnt);
    if (s[n-1]=='0') c.push_back(0);
    int m=c.size();
    if (m<2*k+1) cout << n << endl;
    else {
        vector<int> d;
        cnt=0;
        rep(i,2*k+1) cnt+=c[i];
        d.push_back(cnt);
        rep(i,m-(2*k+1)) {
            cnt+=c[i+2*k+1]-c[i];
            d.push_back(cnt);
        }
        int ma=0;
        rep(i,(d.size()+1)/2) {
            ma=max(ma,d[i*2]);
        }
        cout << ma << endl;
    }

    return 0;
}

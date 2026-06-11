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
const int MAX=1e5+10;
const ll INF=1e18;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,m,x;
    cin >> n >> m >> x;
    vector<int> b(n+1);
    rep(i,m) {
        int a;
        cin >> a;
        b[a]=1;
    }
    rep(i,n) b[i+1]+=b[i];
    
    cout << min(b[x],b[n]-b[x]) << endl;

    return 0;   
}
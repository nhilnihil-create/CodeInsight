#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    rep(i,0,n){
        if(a[i]==b[i]&&b[i]==c[i]) continue;
        if(a[i]!=b[i]&&b[i]!=c[i]&&c[i]!=a[i]) ans+=2;
        else ans++;
    }
    cout<<ans<<endl;
}

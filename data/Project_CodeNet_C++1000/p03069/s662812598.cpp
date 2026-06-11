#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> b(n,0),w(n,0);
    rep(i,n){
        if(s[i]=='#') b[i]=1;
        else w[i]=1;
    }
    vector<int> sb(n+1,0),sw(n+1,0);
    rep(i,n){
        sb[i+1]=sb[i]+b[i];
        sw[i+1]=sw[i]+w[i];
    }

    int ans=n;
    rep(i,n+1){
        ans=min(ans,sb[i]+sw[n]-sw[i]);
    }

    cout<<ans<<endl;
}

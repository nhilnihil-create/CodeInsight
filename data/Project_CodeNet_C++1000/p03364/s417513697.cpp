//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    int n,ans=0,cnt; cin>>n;
    vector<string> s(n,"");
    rep(i,n) cin>>s[i];
    rep(k,n){
        cnt=0;
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                if(s[(i+k)%n][j]==s[(j+k)%n][i]) cnt++;
            }
        }
        if(cnt==n*(n-1)/2) ans+=n;
    }
    cout<<ans<<endl;
}
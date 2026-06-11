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

int main(){
    int n,ans=0; cin>>n;
    vector<string> s(3);
    rep(i,3) cin>>s[i];
    rep(i,n){
        int cnt=0;
        rep(j,3)if(s[j%3][i]==s[(j+1)%3][i]) cnt++;
        if(cnt==0) ans+=2;
        else if(cnt==1) ans++;
    }
    cout<<ans<<endl;
}

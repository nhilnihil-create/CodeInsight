#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll ans=0,tmp=0;
    string s,a="ACGT";
    cin>>s;
    rep(i,s.size()){
        bool ok=false;
        rep(j,4){
            if(s[i]==a[j]) ok=true;
        }
        if(ok){
            tmp++;
            ans = max(ans, tmp);
        }else tmp = 0;
    }
    cout<<ans<<endl;
    return 0;
}
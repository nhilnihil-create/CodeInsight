#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    void solve(){
        ios::sync_with_stdio(false);
        string s;
        cin>>s;
        int n=s.size();
        int ans=n;
        for(int u=1;u<n;u++){
            if(s[u]!=s[u-1])ans=min(ans,max(u,n-u));
        }
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}
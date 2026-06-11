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
    static const int MAXN=2e3+10;
    int N,Z,W;
    int a[MAXN];
    void solve(){
        cin>>N>>Z>>W;
        for(int u=0;u<N;u++)cin>>a[u];
        int ans=abs(a[N-1]-W);
        if(N>1)ans=max(ans,abs(a[N-2]-a[N-1]));
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}
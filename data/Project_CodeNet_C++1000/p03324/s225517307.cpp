#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    int d,n;
    cin>>d>>n;
    if(n==100) n++;
    int ans=n;
    rep(i,d) ans*=100;
    cout<<ans<<endl;
    return 0;
}
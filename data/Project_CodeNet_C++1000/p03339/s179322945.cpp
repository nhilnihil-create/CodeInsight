#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mmax=1000009;

int main(void){
    int n;
    string s;
    cin>>n>>s;
    vector<int> lsums(n+1,0),rsums(n+1,0);
    rep(i,n){
        lsums[i+1]=lsums[i];
        if(s[i]=='W') lsums[i+1]++;
    }
    reverse(s.begin(),s.end());
    rep(i,n){
        rsums[i+1]=rsums[i];
        if(s[i]=='E') rsums[i+1]++;
    }
    reverse(rsums.begin(),rsums.end());
    int ans=n;
    rep(i,n){
        int temp=lsums[i]+rsums[i+1];
        //cout<<temp<<endl;
        chmin(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}

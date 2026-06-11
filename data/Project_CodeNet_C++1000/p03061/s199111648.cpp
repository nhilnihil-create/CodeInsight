#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;


int main(void){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    vector<int> lgcds(n),rgcds(n);
    lgcds[0]=A[0];
    rep(i,n-1) lgcds[i+1]=__gcd(lgcds[i],A[i+1]);
    /*rep(i,n) cout<<lgcds[i]<<" ";
    cout<<endl;*/
    rgcds[n-1]=A[n-1];
    for(int i=n-2;i>=0;--i) rgcds[i]=__gcd(rgcds[i+1],A[i]);
    /*rep(i,n) cout<<rgcds[i]<<" ";
    cout<<endl;*/
    
    int ans=max(lgcds[n-2],rgcds[1]);
    rep(i,n-2){
        int temp=__gcd(lgcds[i],rgcds[i+2]);//A[i+1]以外のgcd
        //cout<<i<<" "<<temp<<endl;
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
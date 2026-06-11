#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N,M,C;cin>>N>>M>>C;
    int ans=0;
    vector<int>B(M);
    rep(i,M){
        cin>>B.at(i);
    }
    vector<vector<int>>A(N,vector<int>(M));
    rep(i,N)rep(j,M){
        cin>>A.at(i).at(j);
    }
    rep(i,N){
        int a=0;
        a+=C;
        rep(j,M){
            a+=A.at(i).at(j)*B.at(j);
        }
        if(a>0)ans++;
    }
    cout<<ans<<endl;
}
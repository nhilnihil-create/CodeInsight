#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string N; cin>>N;

    vector<vector<int>> dp(2,vector<int>(N.size()+1,0));
    rep(n,1,N.size()+1){
        int numN=N.at(n-1)-'0';
        dp.at(0).at(n)=dp.at(0).at(n-1)+numN;
        if(n==1) dp.at(1).at(n)=max(0,numN-1);
        else dp.at(1).at(n)=max(dp.at(0).at(n-1)+max(0,numN-1),
            dp.at(1).at(n-1)+9);
    }

    cout<<max(dp.at(0).at(N.size()),dp.at(1).at(N.size()))<<endl;
}
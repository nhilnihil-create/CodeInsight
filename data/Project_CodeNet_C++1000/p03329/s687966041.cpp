#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int dp[100009];
vector<int>v;

int main(){
    int n;
    cin>>n;
    int a=1,b=1;
    rep(i,0,10){
        if(pow(6,i)<=n)v.push_back(pow(6,i));
        if(pow(9,i)<=n)v.push_back(pow(9,i));
    }
    rep(i,0,100001)dp[i]=100000;
    dp[0]=0;
    rep(i,0,n+1){
        for(auto j:v){
            if(i+j<100001) dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    cout<<dp[n]<<endl;
return 0;
}
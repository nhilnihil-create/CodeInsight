#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;
using ll=long long;
using P=pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int> c;
    int mx=0;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        s--;
        if(c.size()==0||(c.size()>0&&c[c.size()-1]!=s)){
            c.push_back(s);
        }
    }
    n=c.size();
    vector<int> mn(200000,n);
    vector<int> e[n];
    vector<int> dp(n,0);
    for(int i=0;i<n-1;i++)e[i].push_back(i+1);
    for(int i=n-1;i>=0;i--){
        if(mn[c[i]]!=n)e[i].push_back(mn[c[i]]);
        mn[c[i]]=i;
    }
    dp[0]=1;
    const int MOD=1e9+7;
    for(int i=0;i<n;i++){
        for(int j=0;j<e[i].size();j++){
            dp[e[i][j]]+=dp[i];
            dp[e[i][j]]%=MOD;
        }
    }
    cout<<dp[n-1]<<endl;
}


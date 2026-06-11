#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)

long long M = 1000000007;

int n;

int main(int argc, char const *argv[]) {
    cin>>n;
    int M = 21000;
    vector<long long> dp(M,-1),w(n),v(n),s(n);
    vector<pair<long long,int>> tmp(0);
    dp[0] = 0;
    for(int i=0;i<n;++i){
        cin>>w[i]>>s[i]>>v[i];
        tmp.push_back(pair<long long, int>(w[i]+s[i],i));
    }
    sort(tmp.begin(),tmp.end());
    long long res = 0;
    for(int i=0;i<n;++i){
        int k = tmp[i].second;
        for(int l=M-1;l>-1;--l){
            if(l + w[k] < M && l <= s[k] && dp[l] != -1){
                dp[l + w[k]] = max(dp[l+w[k]], dp[l]+v[k]);
                res = max(res,dp[l + w[k]]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
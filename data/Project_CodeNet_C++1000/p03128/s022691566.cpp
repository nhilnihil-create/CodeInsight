#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#include <functional>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll dp[MAX_N];

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    int num[]={0,2,5,5,4,5,6,3,7,6};
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    //cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
    for(int i=0;i<=n;i++){
        dp[i]=-INF;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i-num[a[j]]>=0) dp[i]=max(dp[i],dp[i-num[a[j]]]+1);
        }
    }
    //cout<<dp[n]<<endl;
    string s;
    while(n>0){
        for(int j=0;j<m;j++){
            if(n-num[a[j]]>=0){
                if(dp[n]==dp[n-num[a[j]]]+1){
                    s+=to_string(a[j]);
                    n-=num[a[j]];
                    break;
                }    
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
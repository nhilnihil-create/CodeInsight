#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int n; ll a, b;
    cin>>n>>a>>b;
    int p[5003];
    for(int i=1; i<=n; i++) cin>>p[i];
    p[n+1]=n+1, p[0]=0;
    ll dp[5001];
    dp[0]=0;
    for(int i=1; i<=n+1; i++){
        ll s=0;
        dp[i]=1e18;
        for(int j=i-1; j>=0; j--){
            if(p[i]<p[j]){
                s+=a;
            }else{
                dp[i]=min(dp[i], dp[j]+s);
                s+=b;
            }
        }
    }
    cout<<dp[n+1]<<endl;
    return 0;
}
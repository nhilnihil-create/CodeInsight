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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll dp[1<<21];

int main(){
    int n;
    cin>>n;
    vector< vector<int> >  a(n,vector<int>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dp[0]=1;
    for(int bit=1;bit<1<<n;bit++){
        int i = __builtin_popcount(bit)-1;
        for(int j=0;j<n;j++){
            if(bit>>j & 1 && a[i][j]){
                dp[bit]+=dp[bit^1<<j];
                dp[bit]%=MOD;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}
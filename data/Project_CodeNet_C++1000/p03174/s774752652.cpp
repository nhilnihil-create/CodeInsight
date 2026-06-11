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
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
ll dp[1<<21];

int main(){
    int n;
    cin>>n;
    vector<vector<int> > a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dp[0]=1;
    for(int men=1;men<(1<<n);men++){
        int wom=__builtin_popcount(men);
        wom--;
        for(int j=0;j<n;j++){
            int nmen=men^(1<<j);
            if(nmen>men) continue;
            //cout<<men<<":"<<j<<","<<wom<<endl;
            if(a[j][wom]){
                dp[men]+=dp[nmen];
                dp[men]%=MOD;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}
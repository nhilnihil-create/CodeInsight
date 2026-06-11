#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define int long long int
#define vi vector<int>
#define vvi vector < vi >
#define pii pair<int,int>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define tr(k,st,en) for(int k = st; k <= en ; k++)
#define trb(k,en,st) for(int k = en; k >= st ; k--)
using namespace std;

int nax= 10123;
char *k;
void add_self(int &a, int b){
    a+=b;
    if(a>=mod)
        a-=mod;
}
int32_t main()
{
    std::ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,k;
    cin>>n>>k;
    vector<int> height(n);
    tr(i,0,n-1){
        cin>>height[i];
    }
    vector<int> dp(n+1, inf);
    dp[0] = 0;
    tr(position, 1, n-1){
        tr(jump,1,min(position,k)){
            dp[position] = min(dp[position], abs(height[position] - height[position-jump]) + dp[position-jump]);
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}


//    k = new char[nax];
//    cin>>k;
//    int D;
//    cin>>D;
//    vvi dp(D,vector<int>(2));
//    // dp[sum][sm_already] -> # ways to choose digits;
//    dp[0][0] = 1;
//    int len = strlen(k);
//    tr(where, 0, len-1){
//        vector<vector<int>> new_dp(D,vector<int>(2));
//        tr(sum, 0,  D-1){
//            for(bool sm_already: {false,true}){
//                tr(digit,0,9){
//                    if(digit >(k[where] - '0') and !sm_already){
//                        break;
//                    } else {
//                        add_self(new_dp[(sum+digit)%D][sm_already || digit <(k[where] - '0')],dp[sum][sm_already]) ;
//                    }
//                }
//            }
//        }
//        dp = new_dp;
//    }
//    int ans = (dp[0][false] + dp[0][true] - 1)%mod;
//    cout<<ans<<endl;

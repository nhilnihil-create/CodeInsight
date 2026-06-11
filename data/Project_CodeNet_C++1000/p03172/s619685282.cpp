#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define ll long long int

void add_self(ll& a,ll b){
   a+=b;
   if(a>=mod) a-=mod;
}

void set_self(ll& a,ll b){
    a-=b;
    if(a<0) a+=mod;
}

int main()
{
    int n,candies;
    cin>>n>>candies;
    vector<int>upto(n);
    for(int i=0;i<n;i++) cin>>upto[i];
    vector<long long int> dp(candies+1);
    dp[0]=1;

       for(int i=0;i<n;i++){
               vector<ll> dp1(candies+1);
         for(int cur_candy=candies;cur_candy>=0;cur_candy--){
                int temp=dp[cur_candy];
                int L=cur_candy+1;
               int R=cur_candy+min(upto[i],candies-cur_candy);
               if(L<=R && L<=candies){
                 add_self(dp1[L],temp);
                  if(R+1<=candies) set_self(dp1[R+1],temp);
               }

            }
           ll prefix_sum=0;
           for(int i=0;i<=candies;i++){
             add_self(prefix_sum,dp1[i]);
             add_self(dp[i],prefix_sum);
           }
         }

    cout<<dp[candies];

}

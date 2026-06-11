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
#define tr(k,st,en) for(int k = st; k <= en ; ++k)
#define trb(k,en,st) for(int k = en; k >= st ; --k)

using namespace std;


int32_t main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    
    
    int base = 1;
    while (base <= n) {
        base *= 2;
    }
    vector<int> tree(2*base);
    
    
    vector<int> dp(n+1), height(n), beauti(n);
    map<int, int> till_now;
    for (int i = 0 ; i < n; i++) {
        cin>>height[i];
    }
    for (int i = 0 ; i < n; i++) {
        cin>>beauti[i];
    }
    tr(pos,0,n-1){
        
        // finding with segment tree:
        int x = height[pos] + base;
        int best = 0;
        while (x > 1) {
            if (x%2 == 1) {
                best = max(best, tree[x-1]);
            }
            x/=2;
        }

        //        int ma = *max_element(dp.begin(), dp.begin() + height[pos]);
        dp[height[pos]] = beauti[pos] + best;
        
        for(int index = base + height[pos]; index >=1 ; index /=2){
            tree[index] = max(tree[index], dp[height[pos]]);
        }
        
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
}


//  int n;
//  cin>>n;
//  vector<int> dp(n+1), height(n), beauti(n);
//  map<int, int> till_now;
//  fo`r (int i = 0 ; i < n; i++) {
//      cin>>height[i];
//  }
//  for (int i = 0 ; i < n; i++) {
//      cin>>beauti[i];
//      auto it = till_now.lower_bound(height[i]);
//      it--;
//      dp[i + 1] = max(dp[i] ,dp[it->second] + beauti[i]);
//      till_now.insert({height[i], i});
//  }
//  cout<<dp[n]<<endl;

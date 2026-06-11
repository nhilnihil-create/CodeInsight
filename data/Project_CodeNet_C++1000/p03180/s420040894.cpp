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
using namespace std;

vi score_of_grp;
vi dp;

void rec(int i,const vi & not_taken, int mask, int grp){
    if (i == not_taken.size()) {
        dp[mask ^ grp] = max(dp[mask ^ grp], dp[mask] + score_of_grp[grp]);
        return;
    }
    rec(i+1, not_taken, mask, grp);
    rec(i+1, not_taken, mask, grp ^ (1<<not_taken[i]));
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vvi score(n,vi(n));
    tr(i,0,n-1){
        tr(j,0,n-1){
            cin>>score[i][j];
        }
    }
    int sz = 1ll<<n;
    score_of_grp.resize(sz);
    dp.resize(sz+1, 0);
    //preprocessing for each group
    tr(mask,0,sz - 1){
        tr(i,0,n-1){
            if (mask & (1<<i)) {
                tr(j,i+1,n-1){
                    if (mask & (1<<j)) {
                        score_of_grp[mask] += score[i][j];
                    }
                }
            }
        }
    }
    // iterating for each group to be taken
    tr(mask,0,sz - 1){
        vector<int> not_taken;
        tr(i,0,n-1){
            if (!(mask & (1<<i))) {
                not_taken.push_back(i);
            }
        }
        rec(0, not_taken, mask, 0);
    }
    cout<<dp[sz-1]<<endl;
    return 0;
}

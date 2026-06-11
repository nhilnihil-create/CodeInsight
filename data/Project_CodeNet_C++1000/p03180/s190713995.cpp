#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll groupingRec(vector<vector<ll>> &arr, int n, int mask, vector<ll> &dp,
               vector<ll> &scores){

    if(dp[mask] != -1)
        return dp[mask];
    // Pick a subset of not chosen rabbits among 2^n possible subsets
    // and take that as one group
    ll ans = 0;
    for(int group = 1; group<(1<<n); group++){
        if(!(group&mask)){
            ll currGroupScore = scores[group];
            ll currRecAns = groupingRec(arr, n, mask|group, dp, scores) +
                            currGroupScore;
            if(currRecAns > ans)
                ans = currRecAns;
        }
    }
    dp[mask] = ans;
    return ans;
}

void precalculateScores(vector<vector<ll>> &arr, int n, vector<ll> &scores){

    for(int group=0; group<(1<<n); group++){
        ll score = 0;
        for(int i=0; i<n; i++)
            if((group&(1<<i)))
                for(int j=i+1; j<n; j++)
                    if((group&(1<<j)))
                        score += arr[i][j];
        scores[group] = score;
    }
}

ll grouping(vector<vector<ll>> &arr, int n){

    vector<ll> dp(1<<(n+1), -1);
    vector<ll> scores(1<<(n+1));
    precalculateScores(arr, n, scores);
    ll ans = groupingRec(arr, n, 0, dp, scores);
    return ans;
}

int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int n;
 cin>>n;
 vector<vector<ll>> arr(n, vector<ll>(n));
 for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        cin>>arr[i][j];
 ll ans = grouping(arr, n);
 cout<<ans;
 return 0;
}


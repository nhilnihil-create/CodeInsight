#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll groupingRec(vector<vector<ll>> &arr, int n, int mask, vector<ll> &dp,
               vector<ll> &scores){

    if(dp[mask] != -1)
        return dp[mask];
    // Pick a non-empty subset of not chosen rabbits among 2^n possible subsets
    // and take that as one group
    ll ans = 0;
    // We only go to all the valid subsets
    // (the subsets having only not chosen elements)
    for(int group = mask; group>0; group=(group-1)&mask){
            ll currGroupScore = scores[group];
            // Mark the bits of current group as 0 in the mask
            // indicating that we have picked these elements
            ll currRecAns = groupingRec(arr, n, mask^group, dp, scores) +
                            currGroupScore;
            if(currRecAns > ans)
                ans = currRecAns;

    }
    dp[mask] = ans;
    return ans;
}

void precalculateScores(vector<vector<ll>> &arr, int n, vector<ll> &scores){

    // Store the score for every group combinations

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

    // O(3^n)
    // Earlier, In the recursive function,
    // we were going to all the 2^n subsets
    // regardless of whether the elements in those subsets are available
    // to use or not
    // We denote the unused elements as '1' in the bit (instead of 0)
    // For eg: if we have mask = 00001011  (total 8 elements)
    // Here the bits at position 0, 1, 3 are set meaning we can currently
    // pick these elements and make groups (or subsets) using these elements
    // Earlier we would go to all the 2^8 subsets and check
    // if all the elements in those subsets are unused or not
    // But instead of going to all the 2^n subsets,
    // we can also directly go to all the 2^k subsets
    // (where k is the no. of set bits)
    // So in the above case, we can go to all the 2^3 subsets (instead of 2^8)
    // and that is beneficial for us because out of 2^8 subsets
    // only 2^3 subsets will be valid and we directly go to all the valid subsets

    // Consider following segment of code:

    // for(int mask=0; mask<(1<<n); mask++)
    //      for(int group=mask; group>0; group = (group-1)&mask)
    //          // Do something

    // The time complexity of this segment of code will be O(3^n)
    // Refer to: https://codeforces.com/blog/entry/45223 --> Suboptimal solution


    vector<ll> dp(1<<n, -1);
    vector<ll> scores(1<<n);
    precalculateScores(arr, n, scores);
    // Initially set all the bits (those will be unused elements)
    ll ans = groupingRec(arr, n, (1<<n)-1, dp, scores);
    return ans;
}

int main()
{
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


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Block{
    ll s, w, v;
    bool operator<(const Block &b2){
        ll s1 = s, w1 = w, s2 = b2.s, w2 = b2.w;
        return s1+w1 < s2+w2;
    }
};

ll tower(Block arr[], int n){

    // Suppose if we have 3 blocks with (weight, solidness, value) as:
    // (1, 2, 1)
    // (1, 3, 1)
    // (1, 1, 1)

    // If we try to find the best subsequence having this order itself
    // then we will be able to get the maximum value as 2 only
    // Although the maximum value can be 3
    // by taking all the three in the order: 3, 1, 2
    // Hence to avoid checking of all the possible permutations,
    // we need to sort them in some order

    // Now we need to decide the comparator function for sorting
    // Suppose we have 2 blocks: 1 and 2
    // and they should be such that 1 should be above 2
    // Then a good (or strong) comparator function will ensure
    // that 1 comes before 2 in the array always
    // For 2 to be below 1, this condition must be satisfied: s2 >= w1
    // Also notice that for 1 to be below 2: s1 >= w2 but we don't want this
    // So we also want to satisfy: s1 < w2
    // So that both conditions are satisfied simultaneously:
    //              1) 2 is below 1
    //              2) 1 is never below 2
    // Both conditions must be satisfied to avoid any contradiction
    // Hence there are 2 conditions: s2 >= w1 and s1 < w2
    //                               s2 >= w1 and w2 > s1
    // On combining these 2 conditions: s2+w2 >= w1+s1 or s1+w1 <= s2+w2
    // But again notice that using equal to sign in the inequality
    // will make it again ambiguous
    // For eg: if two (w, s) are (2, 1) and (1, 2)
    //         Then either first block can come below or second block can come below
    //         But we don't want any contradiction or ambiguity
    //         So we remove the equal sign also
    //         Hence we have this condition: s1+w1 < s2+w2
    // (Using equality sign will give Runtime Error)
    // This single condition will ensure that 2 comes below 1 or
    // 2 comes after 1 in the array and also there is no contradiction

    // I have already defined the comparator in the structure definition itself
    sort(arr, arr+n);

    // Now we apply Dynamic Programming:
    // dp[i][j] stores the maximum sum of value of some subsequence
    // considered till i-th element and having the sum of weights as 'j'
    // So whenever a new element comes, we check for which maximum
    // value in dp[i-1][],
    // the solidness of that new element is greater than or equal to
    // the value in dp[i-1][] (sum of some weights) and then update
    // the dp value corresponding to the new sum of weights if better

    // The first dimension of dp[][] will be the no. of elements
    // Now we can take the second dimension to be the sum of all weights
    // but notice that the maximum allowed sum of weights
    // will be limited by the solidness of the bottom most block or
    // the last element which we pick from the array, i.e.
    // the maximum possible sum of weights for any subsequence will
    // be at max (maxS + maxW)
    // where maxS is the max sum of weights of all the blocks except the
    // bottom most block and maxW is the max weight of the bottom most block
    // Hence we can take the second dimension of size (maxS + maxW)

    int maxS = 0, maxW = 0;
    for(int i=0; i<n; i++){
        if(arr[i].s > maxS)
            maxS = arr[i].s;
        if(arr[i].w > maxW)
            maxW = arr[i].w;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(maxS+maxW+1, 0));

    for(int i=1; i<=n; i++){
        int w = arr[i-1].w, s = arr[i-1].s, v = arr[i-1].v;
        // We need to go to all the values of previous row
        // to also copy them to the current row
        for(int j=0; j<=maxS+maxW; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(s >= j)
                dp[i][j+w] = max(dp[i-1][j+w], dp[i-1][j] + v);
        }
    }

    // The maximum value in dp[n][] is our answer
    ll maxSumOfValue = 0;
    for(int i=0; i<=maxS+maxW; i++)
        if(dp[n][i] > maxSumOfValue)
            maxSumOfValue = dp[n][i];

    return maxSumOfValue;
}

ll towerOptimized(Block arr[], int n){
    // Instead of maintaining a 2D array,
    // we can maintain a rolling 1D array like in knapsack
    sort(arr, arr+n);
    int maxS = 0, maxW = 0;
    for(int i=0; i<n; i++){
        if(arr[i].s > maxS)
            maxS = arr[i].s;
        if(arr[i].w > maxW)
            maxW = arr[i].w;
    }
    vector<ll> dp(maxS+maxW+1, 0);
    for(int i=1; i<=n; i++){
        int w = arr[i-1].w, s = arr[i-1].s, v = arr[i-1].v;
        for(int j=s; j>=0; j--)
            dp[j+w] = max(dp[j+w], dp[j]+v);
    }
    ll maxSumOfValue = 0;
    for(int i=0; i<=maxS+maxW; i++)
        if(dp[i] > maxSumOfValue)
            maxSumOfValue = dp[i];

    return maxSumOfValue;
}

int main()
{
 int n;
 cin>>n;
 Block arr[n];
 for(int i=0; i<n; i++)
    cin>>arr[i].w>>arr[i].s>>arr[i].v;
// ll ans = tower(arr, n);
 ll ans = towerOptimized(arr, n);
 cout<<ans;
 return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

/*
3 1 4 2 5
10 20 30 40 50

3 - 4
1 - 2

the last height

two option
1) i am greater than last height, extend the last sequence
2) i am smaller than last height, extend the largest sequence 
        such that the last element is smaller than me


dfs for potential heads 

longest common subsequence

dp[i] - longest common subsequence starting at i

choice: 1) choose to include this character; 2) choose to ignore this character

choices: j < i and arr[j] < arr[i]

*/

using tree_type = ll;

void construct_segment_tree(vector<tree_type>& segtree, vector<tree_type>& a, int n) { 
    // assign values to leaves of the segment tree 
    for (int i = 0; i < n; i++) 
        segtree[n + i] = a[i]; 
  
    /* assign values to internal nodes 
    to compute maximum in a given range */
    for (int i = n - 1; i >= 1; i--) 
        segtree[i] = max(segtree[2 * i], 
                         segtree[2 * i + 1]); 
} 
  
void update(vector<tree_type>& segtree, int pos, tree_type value, int n) { 
    // change the index to leaf node first 
    pos += n; 
  
    // update the value at the leaf node 
    // at the exact index 
    segtree[pos] = value; 
  
    while (pos > 1) { 
  
        // move up one level at a time in the tree 
        pos >>= 1; 
  
        // update the values in the nodes in 
        // the next higher level 
        segtree[pos] = max(segtree[2 * pos], 
                           segtree[2 * pos + 1]); 
    } 
} 
  
tree_type range_query(vector<tree_type>& segtree, int left, int right,  int n) { 
    /* Basically the left and right indices will move 
        towards right and left respectively and with 
        every each next higher level and compute the  
        maximum at each height. */
    // change the index to leaf node first 
    left += n; 
    right += n; 
  
    // initialize maximum to a very low value 
    tree_type ma = INT_MIN; 
  
    while (left < right) { 
  
        // if left index in odd 
        if (left & 1) { 
            ma = max(ma, segtree[left]); 
  
            // make left index even 
            left++; 
        } 
  
        // if right index in odd 
        if (right & 1) { 
  
            // make right index even 
            right--; 
  
            ma = max(ma, segtree[right]); 
        } 
  
        // move to the next higher level 
        left /= 2; 
        right /= 2; 
    } 
    return ma; 
} 

int main() {
    int n;
    
    scanf("%d", &n);
    
    
    vector<int> H(n);
    
    vector<int> B(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &H[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }
    
    int m = n + 1;
    
    vector<ll> dp(m);
    
    // dp[i] - max such that the last height is i
    
    vector<ll> segtree(2 * m); 
    
    construct_segment_tree(segtree, dp, m); 
    
    for (int i = 0; i < n; i++) {
        // dp[H[i]] = B[i];
        dp[H[i]] = B[i];
        // for (int j = 0; j < H[i]; j++) {
            // dp[H[i]] = max(dp[H[i]], dp[j] + B[i]);
        // }
        ll best = range_query(segtree, 0, H[i], m);
        
        // cout << best << endl;
        dp[H[i]] = max(dp[H[i]], best + B[i]);
        update(segtree, H[i], dp[H[i]], m); 
        // for (int j = 0; j < i; j++) {
            // if (H[j] < H[i]) {
                // dp[i] = max(dp[i], dp[j] + B[i]);
            // }
        // }
    }
    
    ll ans = 0;
    
    for (int i = 1; i <= n; i++) {
        ans = max(dp[i], ans);
    }
    
    printf("%lld", ans);

	return 0;
}
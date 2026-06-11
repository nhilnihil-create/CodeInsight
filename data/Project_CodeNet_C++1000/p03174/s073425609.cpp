#include <bits/stdc++.h>

using namespace std;
const int MAXN = 22;
int adj[MAXN][MAXN];
const int MAXS = (1 << 21);
int dp[MAXS + 2];
int n;
const int MOD = 1e9 + 7;

int num_set_bits(int val){
    int count = 0;
    while(val){
        val &= val - 1;
        ++count;
    }
    return count;
}

vector<int> get_bitmask(int val){
    vector<int> bitmask(n, 0);
    int index = 0;
    while(val){
        bitmask[index++] = val % 2;
        val /= 2;
    }
    return bitmask;
}

int bitmast_to_int(vector<int> bitmask){
    int ans = 0;
    for(int i = n - 1; i >= 0; --i){
        ans *= 2;
        ans += bitmask[i];
    }
    return ans;
}

inline int mod(int val, int mod){
    if(val >= mod)
        return val - mod;
    return val;
}

int find_ans(int val = (1 << n) - 1){
    // std::cerr << "DP[" << val << "]\n";
    if(val == 0){
        return 1;    
    }else if(dp[val] != -1){
        return dp[val];
    }else{
        int num_unmatched = num_set_bits(val);
        vector<int> unmatched_women = get_bitmask(val);
        int man = num_unmatched - 1;
        int total_ways = 0;
        for(int woman = 0; woman < n; ++woman){
            if(adj[man][woman] && unmatched_women[woman]){
                int temp_val = val - (1 << woman);
                total_ways = mod(total_ways + find_ans(temp_val), MOD);
            }
        }
        dp[val] = total_ways;
        return total_ways;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> adj[i][j];
        }
    }
    
    for(int i = 0; i < MAXS; ++i){
        dp[i] = -1;
    }
    
    cout << find_ans() << "\n";
    
    return 0;
}
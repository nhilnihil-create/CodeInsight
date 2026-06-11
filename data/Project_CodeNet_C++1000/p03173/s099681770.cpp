#include <bits/stdc++.h>
using namespace std;

const int MAXN = 402;
long long int a[MAXN], sums[MAXN], dp[MAXN][MAXN];
int n;

long long int get_sum(int start, int end){
    if(start == 0)
        return sums[end];
    return sums[end] - sums[start - 1];
}

long long int find_ans(int start = 0, int end = n - 1){
    if(start == end){
        return 0;
    }else if(dp[start][end] != -1){
        return dp[start][end];
    }else{
        long long int min_ans = 1e18;
        long long int interval_sum = get_sum(start, end);
        for(int i = start; i < end; ++i){
            min_ans = min(min_ans, find_ans(start, i) + find_ans(i + 1, end) + interval_sum);
        }
        dp[start][end] = min_ans;
        return dp[start][end];
    }
}

int main(){
	cin >> n;
	long long int sum = 0;
	for(int i = 0; i < n; ++i){
      cin >> a[i];
      sum += a[i];
      sums[i] = sum;
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dp[i][j] = -1;
        }
    }
    
  	long long int ans = find_ans();
    cout << ans << "\n";
  	return 0;
}
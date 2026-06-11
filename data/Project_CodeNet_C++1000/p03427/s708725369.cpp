#include <bits/stdc++.h>
using namespace std;

long long int dp[17][153][2] = {0}, arr[17], m = 0;

long long int getsum(int index, int& n, int flag, long long int sum){
    if(index>n){
        m = max(m, sum);
        return sum;
    }
    if(dp[index][sum][flag]) return dp[index][sum][flag];
    int limit = 0;
    if(flag) limit = arr[n-index+1];
    else limit = 9;
    long long int res = 0;
    for(int i = 0; i <= limit; i++){
       if(i==limit && flag) res += getsum(index + 1, n, 1, sum + i);
       else res += getsum(index + 1, n, 0, sum + i);
    }
    
    return dp[index][sum][flag] = res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int a;
    cin >> a;
        
        int x = 0;
        memset(dp, 0, sizeof(dp));
        while(a){
            x++;
            arr[x] = a%10;
            a /= 10;
        }
        long long int ans = 0;
        ans = getsum(1, x, 1, 0);
    
        cout << m << "\n";
    return 0;
}
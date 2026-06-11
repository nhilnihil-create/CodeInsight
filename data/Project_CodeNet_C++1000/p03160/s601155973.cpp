#include <bits/stdc++.h>

using namespace std;

int main(){
    int num;
    scanf("%d", &num);
    vector <int> arr(num+1), dp(num+1);
    for(int i = 1; i <= num; i++){
        scanf("%d", &arr[i]);
    }
    dp[1] = 0;
    dp[2] = abs(arr[2] - arr[1]);
    for(int i = 3; i <= num; i++){
        int tempA = abs(arr[i] - arr[i-1]) + dp[i-1];
        int tempB = abs(arr[i] - arr[i-2]) + dp[i-2];
        dp[i] = min(tempA, tempB);
    }

    printf("%d\n", dp[num]);    
}
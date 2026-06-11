#include <bits/stdc++.h>
using namespace std;
int n;
int a[2005];
bitset<4000000> dp;
int sum = 0;
int main(){
    scanf("%d",&n);
    dp.reset();
    dp[0] = 1;
    for (int i =0,x;  i < n; i++){
        scanf("%d",&x);
        dp |= dp << x;
        sum += x;
    }
    for (int i = 0; i <= 4000000; i++){
        if (i >= (sum+1)/2 && dp[i]){
            printf("%d\n",i);
            return 0;
        }
    }
}

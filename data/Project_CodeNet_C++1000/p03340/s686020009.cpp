/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int n;
int ar[N];
int pr[N][20];

bool can(int mid , int idx){
     for(int i = 0; i < 20; i++){
        if(pr[mid][i] - pr[idx - 1][i] > 1)
            return 0;
     }
     return 1;
}

int main(){
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
        for(int j = 0; j < 20; j++){
            pr[i][j] = pr[i - 1][j] + ( (ar[i] & (1 << j)) != 0);
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        int l = i , r = n;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(can(mid , i)){
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += l - i + 1;
    }
    printf("%lld\n" , ans);
}
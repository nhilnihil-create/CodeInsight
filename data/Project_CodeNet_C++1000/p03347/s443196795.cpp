#include <bits/stdc++.h>
using namespace std;

int arr[200005];

int main(){
    int n;
    scanf("%d",&n);
    long long ans = 0;
    for (int x = 0; x<n; x++){
        scanf("%d",&arr[x]);
        if (x==0){
            if (arr[x]!=0){
                printf("-1");
                return 0;
            }
        }
        else{
            if (arr[x]>arr[x-1]+1){
                printf("-1");
                return 0;
            }
            if (arr[x]==arr[x-1]+1){
                ans ++;
                continue;
            }
            if (arr[x]>x){
                printf("-1");
                return 0;
            }
            ans += arr[x];
        }
    }
    printf("%lld",ans);
}

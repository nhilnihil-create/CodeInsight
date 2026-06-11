#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[100005];

int32_t main(){
    int n;
    scanf("%lld",&n);
    for (int x = 0; x<n; x++){
        scanf("%lld",&arr[x]);
    }
    int mn = 2;
    int mx = 2;
    for (int x = n-1; x>=0; x--){
        mn = ((mn-1)/arr[x]+1)*arr[x];
        mx = (mx/arr[x])*arr[x]+arr[x]-1;
        if (mx<mn){
            printf("-1");
            return 0;
        }
    }
    printf("%lld %lld",mn,mx);
}

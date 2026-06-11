#include<cstdio>

using namespace std;

int main(){
//     int a = 2;
//     int b = 2;
//     int c = a ^ b;
//     printf("%d\n", c);

    long int n;
    scanf("%ld", &n);
    long int a[n];
    for(int i = 0; i < n; i++){
        scanf("%ld", &a[i]);
    }
    long int l = 0, r = 0;
    long int sm = a[0];
    long int ans = 1;
    while(r < n - 1){
        int x = sm ^ a[r+1];
        if(sm + a[r+1] == x){
            r++;
            sm = x;
            ans += r - l + 1;
        }else if(l < r){
            sm -= a[l];
            l++;
        }else{
            r++;
            l++;
            sm = a[r];
            ans++;
        }
        // printf("%d %d\n", l, r);
        // printf("%d\n", ans);
    }
    printf("%ld\n", ans);
    
}
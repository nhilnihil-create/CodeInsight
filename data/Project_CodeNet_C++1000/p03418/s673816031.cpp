#include<cstdio>

using namespace std;

int main(){
    long int n, k;
    scanf("%ld %ld", &n, &k);
    long int ans = 0;
    if (k == 0) {
        printf("%ld\n", n * n);
    } else {
        for(long int i = 1; i <= n; i++){
            if (i > k){
                if (n % i - k + 1 > 0){
                    ans += (n / i) * (i - k) + (n % i - k + 1);
                }else{
                    ans += (n / i) * (i - k);
                }
            } 
        }
        printf("%ld\n", ans);
    }
    
}
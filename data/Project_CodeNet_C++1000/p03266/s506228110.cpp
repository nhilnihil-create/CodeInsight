#include<cstdio>
#include<cmath>

using namespace std;


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    long int ans = 0;
    if(k % 2 == 0){

        long int num1 = 0;
        long int num2 = 0;
        for(int i = 1; i <= n; i++){
            if (i % k == 0) {
                num1++;
            }else if (i % k == k / 2){
                num2++;
            }
        }
        ans = pow(num1, 3) + pow(num2, 3);
    }else{
        long int num1 = 0;
        for(int i = 1; i <= n; i++){
            if (i % k == 0) {
                num1++;
            }
        }
        ans = pow(num1, 3);
    }
    printf("%ld\n", ans);
}
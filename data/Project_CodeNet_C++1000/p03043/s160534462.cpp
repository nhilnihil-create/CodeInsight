#include<iostream>

int main(void){
    int n, k;
    std::cin >> n >> k;
    double cp = 1.0;
    int i = n;
    double ans = 0;
    int cur = 1;
    int cnt = 0;
    while(i > 0){
        if(cur * i < k){
            ans += cp * cnt / n;
            cp /= 2.0;
            cur *= 2;
            cnt = 0;
        }else if(i == 1){
            cnt++;
            ans += cp * cnt / n;
            i--;
        }else{
            cnt++;
            i--;
        }
    }
    printf("%.10f\n", ans);
    return 0;
}

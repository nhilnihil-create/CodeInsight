#include <bits/stdc++.h>

int main(){
    long long N;
    std::cin >> N;
    
    if(N == 0){
        std::cout << 0 << std::endl;
    }
    
    long long dec = -1;
    std::string ans;
    while(N != 0){
        if(N > 0){
            long long cur = 1;
            long long plus = 0;
            while(N > cur){
                plus += 2;
                cur = cur + ((long long)1 << plus);
            }
            N -= 1 << plus;
            if(dec == -1){
                ans = "1";
                dec = plus - 1;
            }else{
                while(dec != plus){
                    ans = ans + "0";
                    dec--;
                }
                ans = ans + "1";
                dec--;
            }
        }else{
            long long cur = -2;
            long long plus = 1;
            while(N < cur){
                plus += 2;
                cur = cur + -1 * ((long long)1 << plus);
            }
            N -= -1 * (1 << plus);
            if(dec == -1){
                ans = "1";
                dec = plus - 1;
            }else{
                while(dec != plus){
                    ans = ans + "0";
                    dec--;
                }
                ans = ans + "1";
                dec--;
            }
        }
    }
    while(dec >= 0){
        ans = ans + "0";
        dec--;
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
    
}

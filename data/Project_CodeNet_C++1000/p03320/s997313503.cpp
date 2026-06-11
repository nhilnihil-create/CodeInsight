#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#include <array>
 
using namespace std;
constexpr int64_t INF = 1000000000000010;
 
int64_t Func(int64_t n){
    int64_t sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
 
int main(){
    int64_t K;
    cin >> K;
 
    for(int i = 1; i <= min(9, int(K)); ++i){
        cout << i << endl;
    }
    K -= 9;
    int64_t num = 10;
    int64_t plus = 1;
    while(K > 0){
        int64_t ans = num + plus;
        for(int64_t i = 2; i <= 1000; ++i){
            int64_t po = num + i * plus;
            if(po * Func(ans) <= ans * Func(po)){
                ans = po;
            }
        }
        cout << ans << endl;
        while(plus <= ans / 10000){
            plus *= 10;
        }
        num = ans;
        --K;
    }
}
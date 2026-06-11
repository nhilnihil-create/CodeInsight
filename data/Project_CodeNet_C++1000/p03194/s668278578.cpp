#include <cmath>
#include <limits>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAXSIZE 1000000
#define MAXL 300
typedef long long int lli;

lli pow_lli(lli a, lli x){
    lli value = 1;
    for(lli i = 0; i < x; i++){
        value *= a;
    }
    return value;
}

int main(){
    lli n, p;
    cin >> n >> p;

    if(n == 1){
        cout << p << endl;
    }else{
        lli p_copy = p, ans = 1;
        lli nums[MAXSIZE] = {};
        
        lli sisu;
        for(lli i = 2; i < sqrt(p); i++){
            if(nums[i] == 0){
                sisu = 0;
                while(p_copy % i == 0){
                    p_copy /= i;
                    sisu++;
                }

                if(sisu > 0){
                    //cout << i << "^" << sisu << endl;
                    ans *= pow_lli(i, (sisu / n));
                    //cout << "ans = " << ans << endl;
                }

                for(lli j = i * i; j < sqrt(p); j += i){
                    if(nums[j] == 0){
                        nums[j] = -1;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}    
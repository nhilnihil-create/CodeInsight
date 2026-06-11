#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <math.h>
using namespace std;

long long power(long long a,long long n){
    long long ans=1;
    while(0<n){
        if(n%2==0){
            a*=a;
            n>>=1;
        }else{
            ans*=a;
            n--;
        }
    }
    return ans;
}

int main(){
    long long N, P, PP, max = 1, count = 0;
    cin >> N >> P;
    PP = P;
    long long A_p = 0;
    if(N == 1){
        cout << P << endl;
    }else{
        for(int i = 2; PP >= power(i,N); i++){
            while(PP%i == 0){
                PP /= i;
                count ++;
            }
            while(count >= N){
                count -= N;
                max *= i;
            }
            count = 0;
        }
        cout << max << endl;
    }

    return 0;
}
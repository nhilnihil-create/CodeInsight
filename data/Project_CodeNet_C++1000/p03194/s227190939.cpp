#include <iostream>
using namespace std;

long solve(long n, long p){
    if(n == 1){
        return p;
    }
    long res = 1, count = 0;
    for(long i = 2; i*i <= p; i++){
        while(p % i == 0){
            count++;
            p /= i;
            if(count >= n){
                res *= i;
                count = 0;
            }
        }
        count = 0;
    }
    return res;
}

int main(){
    long n, p;
    cin >> n >> p;
    cout << solve(n, p) << endl;
    return 0;
}
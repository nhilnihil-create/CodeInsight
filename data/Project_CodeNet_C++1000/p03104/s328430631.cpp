
#include <iostream>
#include <cstdio>
using namespace std;

long long f(long long n){
    if(n % 2 == 0){
        if(n/2 % 2 == 0){
            return n;
        }
        else{
            return 1^n;
        }
    }
    else{
        if((n+1)/2 % 2 == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
}


int main(){
    long long a, b;
    cin >> a >> b;
    if(a == 0){
        cout << f(b) << endl;
        return 0;
    }
    long long ans = f(b)^f(a-1);
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }

    return gcd(y, x%y);
}

long long lcm(long long x, long long y){

    return x/gcd(x,y)*y;
}

int main(){

    long long n;
    cin >> n;

    long long l = 1;
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        long long a;
        cin >> a;
        sum += a-1;

        //l = lcm(a, l);
    }

    cout << sum << endl;

    return 0;
}
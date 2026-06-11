#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long double sum = 0;
    long double a[n];
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    long double average = sum/((long double) n);

    long double minv = 1e9;
    for(long long i = 0; i < n; i++){
        a[i] = abs(a[i]-average);
        minv = min(minv, a[i]);
    }

    for(long long i = 0; i < n; i++){
        if(minv == a[i]){
            printf("%lld\n", i);
            return 0;
        }
    }
}
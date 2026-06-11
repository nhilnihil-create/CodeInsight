#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    long long N, K; cin >> N >> K;
    if ( K % 2 == 1) {
        long a = N/K;
        cout << a*a*a << endl;
    } else {
        long long a = N/K;
        long long b = (N+(K/2)) / K;
        cout << a*a*a + b*b*b << endl;
    }
}
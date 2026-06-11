#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long A, B ,C;
    cin >> A >> B >> C;
    if( A + B >=  C){
        printf("%lld\n", B+C);
    }
    else{
        printf("%lld\n", A+B+B+1);
    }
}
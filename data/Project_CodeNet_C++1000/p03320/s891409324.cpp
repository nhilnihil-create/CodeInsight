#include<iostream>
#include<cmath>

using namespace std;

long long Sunuke(long long x){
    long long sum = 0;
    while(x > 0){
        sum += x%10;
        x = x/10;
    }
    return sum;
}
int main(){
    long long N,K,d;
    d=1;
    cin >> K;
    N = 1;
    cout << 1 << endl;
    for(long long i = 1;i<K;i++){
        if((N+d*10)*Sunuke(N+d)<(N+d)*Sunuke(N+d*10)){
            d *= 10;
        }
        N += d;
        cout << N << endl;
    }
    return 0;
}
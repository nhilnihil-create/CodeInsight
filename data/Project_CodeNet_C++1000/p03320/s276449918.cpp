#include<iostream>
#include<cmath>
using namespace std;


int K;
long long ans[100000];

long long pow(int a, int x){
    long long ret = 1;
    for(int i = 0; i < x; i++){
        ret *= a;
    }
    return ret;
}

long long S(long long x){
    long long ret = 0;
    for(int i = 0; i < 16; i++){
        ret += (x%10);
        x /= 10;
    }
    return ret;
}
        

long long f(long long N){
    long long ret = N;
    double feature = 1.0 * N / S(N);
    for(int d = 0; d <= log10(N) + 1; d++){
        long long x = pow(10, d+1) * (N / pow(10, d+1) + 1) - 1;
        if(1.0 * x / S(x) < feature){
            ret = x;
            feature = 1.0 * x / S(x);
        }
    }
    return ret;
}


int main(){
    cin >> K;
    long long N = 1;
    for(int k = 0; k < K; k++){
        ans[k] = f(N);
        N = ans[k] + 1;
    }
    for(int k = 0; k < K; k++){
        cout << ans[k] << endl;
    }
}
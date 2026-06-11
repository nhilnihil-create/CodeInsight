#include <iostream>
#include <cstdio>
using namespace std;
#define N 200010

typedef unsigned long long i64;
i64 n, X, x[N], sum[N], Ans = 1LL << 62;

int main(){
    cin >> n >> X;
    for (int i = 1; i <= n; i++){
        i64 tmp;
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }
    for (int k=1; k <= n; k++){
        //throw energy
        i64 energy = (i64)k*(i64)X;
        for (int i=0; i <= n/k; i++){

            int weight = i == 0 ? 5 : 5 + 2*(i - 1);
            int M = n - i*k;
            int m = (M - k) >= 0LL ? M - k : 0;
            energy += (i64)weight * (sum[M]-sum[m]);
            if (energy < 0) break;
            //printf("%d,%d,,M%d,m%d,sum[M]-sum[m]%llu\n",k,weight,M,m, sum[M]-sum[m]);
        }
        energy += n*X;
        if (Ans >= energy){
            Ans = energy;
        }
    }
    cout << Ans << endl;
}
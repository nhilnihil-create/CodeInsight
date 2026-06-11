#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;


int main(void){
    int N;
    cin >> N;
    printf("%d\n", N*(N-1)/2 - N/2);
    if(N % 2 == 0){
        for(int i = 1; i < N; i++){
            for(int j = i + 1; j <= N; j++){
                if(i + j != N+1) printf("%d %d\n", i, j);
            }
        }
    }
    else{
        for(int i = 1; i < N; i++){
            for(int j = i + 1; j <= N; j++){
                if(i + j != N) printf("%d %d\n", i, j);
            }
        }
    }    
    
    
}

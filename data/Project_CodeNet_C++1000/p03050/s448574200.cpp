#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)
 
int main(){
    long long N;
    cin >> N;
    long long res = 0;
    for(long long i=1;i*i<=N;i++){
        if(N % i == 0){
            long long j = i-1;
            long long k = N / i - 1;
            if(j && N/j == N%j) res += j;
            if(i * i != N && k && N/k == N%k) res += k;
        }
    }
    cout << res << endl;
    return 0;
}
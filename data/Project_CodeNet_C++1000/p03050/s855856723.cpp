#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ans=0;
    cin >> N;

    for(long long int i=2;i*i<=N;i++){
        if(N%i==0){
            long long int a,b;
            a = i-1;
            b = N/i -1;

            if(N/a == N%a){
                ans += a;
            }

            if(N/b == N%b){
                ans += b;
            }
        }
    }

    if(N!=1 && N/(N-1) == N%(N-1)){
        ans += N-1;
    }

    cout << ans << endl;
}
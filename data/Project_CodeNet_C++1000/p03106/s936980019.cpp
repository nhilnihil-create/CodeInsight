#include <bits/stdc++.h>
using namespace std;
using ll=long long;

  

int main() {
    ll A,B,K;
    cin >> A >> B >>K;
    ll num =0;
    for(int i=100;i>=0;--i){
        if(A%i ==0 && B%i==0){
            num++;
        }
        if(num == K){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
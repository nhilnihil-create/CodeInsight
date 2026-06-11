#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, K,number = 1;
    cin >> N>> K;
    
    rep(i,N){
        if (number > K){
            number += K;
        }
        else{
            number *= 2;
        }
    }
    cout << number << endl;
    
}
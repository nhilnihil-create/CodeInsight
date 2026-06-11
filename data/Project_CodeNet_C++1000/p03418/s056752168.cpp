#include <iostream>
using namespace std;
using ll = long long;
#include <bits/stdc++.h>

ll func(int N, int b, int K){
    ll count = 0;
    ll countRem = max(N % b + 1 - K, 0);
    ll countCycle = b - K;
    ll numCycle = std::floor(N / b);
    return numCycle * countCycle + countRem;
}

int main(){
    int N, K;
    cin >> N >> K;
    ll count = 0;
    if (K == 0){
        count = N;
        count *= N;
    } else {
        for (int b=K+1; b<=N; b++){
            //cout << b << ":" << func(N, b, K) << endl;
            count += func(N, b, K);
        }
    }
    cout << count << endl;
}
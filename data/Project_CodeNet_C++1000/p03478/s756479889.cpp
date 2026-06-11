#include <bits/stdc++.h>
using namespace std;

int siguma(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int N , A, B;
    cin >> N >> A >> B;

    int total = 0;
    for(int i = 1; i <= N; i++){
        int sum = siguma(i);
        if(A <= sum && sum <= B){
            total += i;
        }

    }

cout << total << endl;
}
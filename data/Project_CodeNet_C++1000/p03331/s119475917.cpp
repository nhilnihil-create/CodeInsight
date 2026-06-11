#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int digit_sum(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int min_sum = 9*5;
    rep(i, N){
        if(i==0) continue;
        int A = i;
        int B = N - A;

        int sum_A = digit_sum(A);
        int sum_B = digit_sum(B);

        int tmp = sum_A + sum_B;
        min_sum = min(tmp, min_sum);
    }
    cout << min_sum << endl;
}
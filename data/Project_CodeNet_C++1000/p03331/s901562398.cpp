#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int waru(int n){
    int sum;
    sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }

    return sum;
}

int main(){
    int N, M, min, sum1, sum2;
    cin >> N;
    min = 99999;
    for(int i = 1; i < N; i++){
        M = N - i;
        sum1 = waru(i);
        sum2 = waru(M);
        if(min > sum1 + sum2){
            min = sum1 + sum2;
        }
    }

    cout << min << endl;
}
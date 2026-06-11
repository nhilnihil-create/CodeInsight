#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K,sum;
    cin >> N;
    cin >> K;
    sum = 1;
    for(int i = 0; i < N;i++){
        if(sum * 2 < sum + K){
            sum = sum * 2;
        }
        else{
            sum = sum + K;
        }
        
    }

    cout << sum << endl;
}
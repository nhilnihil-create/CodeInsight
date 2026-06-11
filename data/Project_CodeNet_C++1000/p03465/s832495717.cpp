#include <iostream>
#include <cstring>
#include <bitset>

#define M 4000000

using namespace std;

int main(){
    int N;
    int A[2000];
    int sum = 0;
    bitset<M+1> dp;
    bitset<M+1> dp_;
    
    dp[0] = 1;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    for(int i = 0; i < N; i++){
        dp_ = dp << A[i];
        dp |= dp_;
    }
    int m = (sum+1)/2;
    for(int i = m; i <= sum; i++){
        if(dp[i]){
            cout << i << endl;
            return 0;
        }
    }
}
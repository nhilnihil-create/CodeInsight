#include <iostream>
#include <bitset>
using namespace std;

int N,A[2010];

int main(){
    cin >> N;
    int sum = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
    }
    bitset<4000010> dp;
    dp.set(0);
    for(int i=0;i<N;i++){
        bitset<4000010> pre;
        pre |= dp;
        pre |= (dp<<A[i]);
        swap(dp,pre);
    }
    for(int i=(sum+1)/2;i<=4000000;i++){
        if(dp[i]){
            cout << i << endl;
            return 0;
        }
    }
}
#include<iostream>

using namespace std;

int Consecutive_Integers(int n,int k){
    return n-k+1;
}

int main(){
    int N,K;
    cin >> N >> K;

    cout << Consecutive_Integers(N,K) << endl;

    return 0;
}

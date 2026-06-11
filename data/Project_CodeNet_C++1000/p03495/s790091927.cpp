#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K;
    cin >> N >> K;
    int A[200010] = {};
    int B[200010] = {};
    
    for(int i = 1 ; i <= N ; i++){
        cin >> A[i];
        B[A[i]]++;
    }
    
    sort(B,B+N+1,greater<int>());
    
    int a = 0;
    for(int i = 0 ; i < K ; i++){
        a +=B[i];
    }
    int b = 0;
    for(int i = 0 ; i <= N ; i++){
        b +=B[i];
    }
    cout << b - a << endl;
    return 0;
}
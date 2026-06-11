#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long A, B;
    int K;
    cin >> A >> B >> K;

    long long upper_A = A+K-1;
    long long lower_B = B-K+1;
    
    if(A+K-1 < B-K+1){
        for(long long i=A; i<=upper_A; i++){
            cout << i << endl;
        }
        for(long long i=lower_B; i<=B; i++){
            cout << i << endl;
        }
    }else{
        for(long long i=A; i<=B; i++){
            cout << i << endl;
        }
    }
    return 0;
}
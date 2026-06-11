#include<bits/stdc++.h>
using namespace std;

int main(){
   
    int A, B, K;
    cin >> A >> B >> K;

    int m = min(A, B);
    int count = 0;
    for(int i = m; i >= 0; i--) {
        if(A % i == 0 && B % i == 0) {
            count++;
        }
        if(count == K) { cout << i; return 0; }
    }
    return 0;
}
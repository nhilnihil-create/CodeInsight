#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, K;
    cin >> A >> B >> K;

    int counter = 0;
    int ans = 0;
    for(int i = min(A, B); i >= 1; i--){
        if(A % i == 0 && B % i == 0){
            counter++;
        }
        if(counter == K){
            ans = i;
            break;
        }
    }

    cout <<  ans << endl;
    return 0;
}
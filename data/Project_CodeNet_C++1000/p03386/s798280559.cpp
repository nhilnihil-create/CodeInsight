#include<iostream>
using namespace std;

int main(){
    int A, B, K;
    cin >> A >> B >> K;
    for (int i=A; i<=B; i++){
        if ((B-K+1 <= i) | (i <= A+K-1)){
            cout << i << endl;
        }
    }
    return 0;
}
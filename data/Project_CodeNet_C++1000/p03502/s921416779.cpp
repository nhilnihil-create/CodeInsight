#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, moveN;
    int f_N = 0;
    cin >> N;
    moveN = N;
    while(moveN != 0){
        f_N += moveN % 10;
        moveN /= 10;
    }
    if(N % f_N == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
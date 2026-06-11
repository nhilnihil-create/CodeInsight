#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N,A=0;
    cin >> N;
    int a = log10(N);
    for(int i=0; i<=a; i++){
        int b = N / pow (10, a-i);
        A = A + b % 10;
    }
    if (N % A == 0){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
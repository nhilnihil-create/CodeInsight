#include <iostream>
#include <string>
#include <algorithm>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <math.h>
using namespace std;

int sum(int N){
    int s = 0;
    while(N > 0){
        s += N % 10;
        N /= 10;
    }
    return s;
}

int main(){
    int N;
    cin >> N;
    int A, B, s;
    int m = 1000000000;
    for (int i=1; i<N; i++){
        A = i;
        B = N-i;
        s = sum(A) + sum(B);
        if (m>s) m=s;
    }
    cout << m << endl;
}
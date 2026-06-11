#include<iostream>
using namespace std;
int main(){
    int N, A, B, sumA, sumB, sum, m = 1000;
    cin >> N;
    for(int a = 1; a < N; a++){
        A = a;
        B = N - A;
        sumA = 0;
        sumB = 0;
        for(int i = 0; i < 7; i++){
            sumA += A % 10;
            sumB += B % 10;
            A /= 10;
            B /= 10;
        }
        sum = sumA + sumB;
        if(sum < m) m = sum;
    }
    cout << m << endl;
}
#include <iostream>
#include <stdio.h>
#include <vector> 
using namespace std;

int main(void) {
    int N; cin >> N;
    if (N % 2 == 1) {
        N = N * 2;
    }
    cout << N << endl;
}
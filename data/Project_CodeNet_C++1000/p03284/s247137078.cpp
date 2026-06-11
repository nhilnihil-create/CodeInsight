#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    int N, K; cin >> N >> K;
    int answer = (N % K) != 0 ? 1 : 0;
    cout << answer << endl;
}
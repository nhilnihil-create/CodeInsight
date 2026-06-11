#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N, K; cin >> N >> K;
    vector<int> x(N);
    int i = 0;
    int answer = pow(10, 9);
    int sum = 0;
    int sum2 = 0;
    while(i < N){
        cin >> x[i];
        i++;
    }
    K--;
    i = 0;
    while (i < N-K) {
        sum = 0;
        sum2 = 0;
        if (x[i] < 0 && x[i+K] >= 0) {
            sum = x[i + K] - x[i] * 2;
            sum2 = x[i + K] * 2 - x[i];
            sum = min(sum, sum2);
        } else if (x[i] < 0) {
            sum = abs(x[i]);
        } else {
            sum = x[i + K];
        }
        answer = min(answer, sum);
        i++;
    }
    
    cout << answer << endl;
}

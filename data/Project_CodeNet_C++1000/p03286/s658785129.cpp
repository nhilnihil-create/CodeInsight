#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;

int main(void){
    int N; cin >> N;
    string answer = "";
    while(N){
        if (N % 2) {
            answer = "1" + answer;
        } else {
            answer = "0" + answer;
        }
        int r = N % 2;
        if (r < 0) r+=2;
        N -= r;
        N /= -2;
    };
    if(answer.empty()) {
        answer = "0";
    }
    cout << answer << endl;
}
#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm> 
using namespace std;
int main(void){
    int N; cin >> N;
    int i = 0;
    int answer = 0;
    vector<int> a(N);
    while(i < N) {
        cin >> a[i];
        answer += a[i];
        i++;
    }
    cout << answer - N << endl;
}
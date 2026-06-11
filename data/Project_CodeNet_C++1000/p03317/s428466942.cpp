#include <iostream>
#include <stdio.h>
#include <vector> 
using namespace std;
int main(void){
    int N, K; cin >> N >> K;
    int i = 0;
    int index = 0;
    vector<int> a(N);
    while(a.size() > i){
        cin >> a[i];
        if (a[i] == 1) {
            index = i;
        }
        i++;
    }
    int b = 0;
    if ((N - 1) % (K - 1) == 0) {
        b = 0;
    } else {
        b = 1;
    }
    cout << (N - 1) / (K - 1) + b << endl;
}
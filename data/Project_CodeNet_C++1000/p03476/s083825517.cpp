#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100010;
bool isNotPrime[MAX] = {0};

void setPrime(){
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    for(int i = 2; i <= MAX/2; i++){
        if(isNotPrime[i])continue;
        for(int k = 2; k*i <= MAX; k++){
            isNotPrime[k*i] = 1;
        }
    }
}

int main(){
    setPrime();
    int accumulation[MAX] = {0};
    for(int i = 1; i < MAX; i++){
        if(i%2 && !isNotPrime[i] && !isNotPrime[(i + 1)/2]) accumulation[i] = accumulation[i - 1] + 1;
        else accumulation[i] = accumulation[i - 1];
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int l,r;
        cin >> l >> r ;
        cout << accumulation[r] - accumulation[l-1] << endl;
    }
}
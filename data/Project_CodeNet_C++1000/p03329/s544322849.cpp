#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> kane(N+1);
    for(int i = 0; i < N+1; i++){
        kane[i] = i;
    }
    for(int i = 9 ; i < N+1; i = i*9){
        for (int j = 0; j < N + 1; j++){
            if (j+i < N+1){
                kane[j+i] = min(kane[j+i],kane[j]+1);
            }
        }
    }
    for(int i = 6; i < N+1; i = i*6){
        for (int j = 0; j < N+1; j++){
            if(j+i < N+1){
                kane[j+i] = min(kane[j+i],kane[j]+1);
            }
        }
    }
    cout << kane[N] << endl;
}
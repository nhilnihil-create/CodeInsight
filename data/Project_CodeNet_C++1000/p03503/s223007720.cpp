#include "bits/stdc++.h"
using namespace std;

int main(){
    int N; cin >> N;
    int F[N][10];
    for(int i=0; i<N; i++){
        for(int j=0; j<10; j++){
            cin >> F[i][j];
        }
    }
    int P[N][11];
    for(int i=0; i<N; i++){
        for(int j=0; j<11; j++){
            cin >> P[i][j];
        }
    }
    long long int cur, mx=-10000000000;

    for(int bit = 1; bit < (1<<10); bit++){
        cur = 0;
        for(int i = 0; i < N; i++){
            int open = 0;
            for(int j=0; j<10; j++){
                if(((bit>>j)&1) & F[i][j]) open++;
            }
            cur += P[i][open];
        }
        if(mx<cur) mx=cur;
    }
    cout << mx << endl;
    return 0;
}
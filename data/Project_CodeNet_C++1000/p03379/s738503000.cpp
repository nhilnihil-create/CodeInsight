#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    long long X[N];
    long long Y[N];
    
    for(int i = 0; i < N;i++){
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(X,X+N);
    
    for(int i = 0; i < N;i++){
     if(Y[i]<X[N/2]) cout << X[N/2] << endl;
     else cout << X[N/2 - 1] << endl;
    }
}

    
    


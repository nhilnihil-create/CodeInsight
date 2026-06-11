#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        X[i] = a;
        Y[i] = a;
    }
    
    sort(Y.begin(), Y.end(), greater<int>());
    
    vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
        if (X[i] < Y[N / 2 - 1])
        {
            B[i] = Y[N / 2 - 1];
        } else
        {
            B[i] = Y[N / 2];
        }
        
        
        cout << B[i] << endl;
        
    }
    
    
    return 0;
    
}
#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define P pair<int, int>

int main(){
    int N;
    cin >> N;
    
    int A[N];
    
    int L = 0, S = 0;
    int posL = 0, posS = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        
        if(A[i] >= L){
            L = A[i];
            posL = i;
        }
        if(A[i] <= S){
            S = A[i];
            posS = i;
        }
    }
    
    if(S == 0){
        cout << N - 1 << endl;
        for(int i = 0; i < N - 1; ++i){
            cout << i + 1 << " " << i + 2 << endl;
        }
        return 0;
    }
    if(L == 0){
        cout << N - 1 << endl;
        for(int i = N - 1; i > 0; --i){
            cout << i + 1 << " " << i << endl;
        }
        return 0;
    }
    
    if(L + S >= 0){
        cout << 2 * N - 1 << endl;
        for(int i = 0; i < N; ++i){
            cout << posL + 1 << " " << i + 1 << endl;
        }
        for(int i = 0; i < N - 1; ++i){
            cout << i + 1 << " " << i + 2 << endl;
        }
        return 0;
    }
    if(L + S < 0){
        cout << 2 * N - 1 << endl;
        for(int i = 0; i < N; ++i){
            cout << posS + 1 << " " << i + 1 << endl;
        }
        for(int i = N - 1; i > 0; --i){
            cout << i + 1 << " " << i << endl;
        }
        return 0;
    }
    
    
}

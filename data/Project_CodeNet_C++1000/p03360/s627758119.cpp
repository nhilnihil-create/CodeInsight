#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    if (A < B) swap(A, B);
    if (A < C) swap(A, C);
    if (B < C) swap(B, C);
    for (int i = 0; i < K; i ++){
        A *= 2;
    }
    cout << A + B + C << endl;
    
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, N, M ,K;

    cin >> N >>A>>B;

    C = min(A, B);
    if(A+B-N>0) K = A+B-N;
    else K = 0;

    cout << C << " " << K << endl;

}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    int M=-1001001001;
    cin >> A >> B;
    M = max(M, (A+B));
    M = max(M, (A-B));
    M = max(M, (A*B));
    cout << M << endl;
}
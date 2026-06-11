#include<bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C;
    int K;
    cin >> A >> B >> C >> K;
    int cnt = 1;
    for(int i = 0; i < K; i++) {
        cnt *= 2;
    }
    cout << A+B+C+max(max(A,B),C)*cnt-max(max(A,B),C) << endl;
}


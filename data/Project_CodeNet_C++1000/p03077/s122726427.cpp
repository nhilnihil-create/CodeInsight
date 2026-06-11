#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    long long int N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;
    long long int m = min(A, min(B, min(C, min(D, E))));

    if(N%m==0){
        cout << N/m + 4 << endl;
    }
    else{
        cout << N/m + 5 << endl;
    }
}

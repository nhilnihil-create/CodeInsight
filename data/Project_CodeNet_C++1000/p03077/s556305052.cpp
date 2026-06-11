#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N,A,B,C,D,E;
    cin >> N >> A >> B >> C >> D >> E;
    
    int64_t F = min(A,min(B,min(C,min(D,E))));
    
    if ( N % F == 0 ){
        cout << N / F + 4 << endl;
    } else {
        cout << N / F + 5 << endl;
    }
    return 0;
}

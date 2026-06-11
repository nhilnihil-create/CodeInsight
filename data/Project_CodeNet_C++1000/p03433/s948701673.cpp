#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,N;
    cin >> N >> A;
    bool ok = false;
    for (int X=0; X<=N; X+=500) {
        if(N-X<=A){
            ok = true;
        }
    }
    if(ok == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

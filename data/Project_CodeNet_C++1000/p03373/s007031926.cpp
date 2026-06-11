#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,X,Y;
    cin >>A>>B>>C>>X>>Y;

    if(C * 2 > A+B) {
        cout << A*X + B*Y;
    } else {
        int pos = max(X, Y);
        int neg = min(X, Y);
        if(X > Y) cout << min(C * pos * 2, C * neg * 2 + (pos - neg) * A); 
        if(Y > X) cout << min(C * pos * 2, C * neg * 2 + (pos - neg) * B); 
        if(Y == X) cout << C * pos * 2; 

    }
    cout << endl;
    return 0;
}
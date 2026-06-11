#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)n; i++)

int main() {
    int N, P=0, W=0, G=0, Y=0;
    cin >> N;

    rep(i,N) {
        string S;
        cin >> S;
        if (S == "P") P++;
        else if (S == "W") W++;
        else if (S == "G") G++;
        else if (S == "Y") Y++;        
    }
    if ((P > 0) && (W > 0) && (G > 0) && (Y > 0)) cout << "Four" << endl;
    else cout << "Three" << endl;
}
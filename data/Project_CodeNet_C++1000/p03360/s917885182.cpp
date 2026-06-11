#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int K; 
    cin >> K;

    int M = max(a, max(b, c));
    int S = a+b+c;

    for(int i=1; i<=K; i++){
        S += M;
        M *= 2;
    }

    cout << S << endl;
}

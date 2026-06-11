#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; int w;
    cin >> S >> w;
    int N = S.length();
    for (int i = 0; i < N; i++) {
        if (i % w == 0) {
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}
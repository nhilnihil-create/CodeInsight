#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        if(S[i] == 'R')a++;
        else b++;
    }
    cout << ((a > b) ? "Yes" : "No") << endl;
    return 0;
}
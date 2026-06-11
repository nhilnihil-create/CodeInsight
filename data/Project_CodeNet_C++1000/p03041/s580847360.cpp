#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    S[K-1]=tolower(S[K-1]);
    cout << S << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T="keyence"; cin >> S;
    int N=S.size();
    for (int i=0;i+6<N;++i){
        if (S.substr(i,7)==T){
            cout << "YES" << '\n';
            return 0;
        }
    }
    for (int i=1;i<7;++i){
        int ok=1;
        for (int j=0;j<7;++j){
            if (j<i&&S[j]!=T[j]) ok=0;
            if (i<=j&&S[N-7+j]!=T[j]) ok=0;
        }
        if (ok){cout << "YES" << '\n'; return 0;}
    }
    cout << "NO" << '\n';
}
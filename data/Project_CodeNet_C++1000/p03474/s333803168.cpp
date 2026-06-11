#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    int A, B;
    string S;
    cin >> A >> B >> S;

    bool ok = true;
    rep(i, A){
        if(isdigit(S[i]) == false) ok = false;
    }
    if(isdigit(S[A])) ok = false;
    repa(i, A+1, A+B){
        if(isdigit(S[i]) == false) ok = false;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.length();
    if(N < 5){
        cout << "NO" << endl;
        return 0;
    }
    if(S[0] != 'A')S = "A" + S;
    if(S[4] != 'A')S = S.substr(0, 4) + "A" + S.substr(4);
    if(S[6] != 'A')S = S.substr(0, 6) + "A" + S.substr(6);
    if(S[8] != 'A')S = S + "A";
    if(S == "AKIHABARA")cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
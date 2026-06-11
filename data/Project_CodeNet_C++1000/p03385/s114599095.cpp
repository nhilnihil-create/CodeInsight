#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    char S[3];
    cin >> S;
    sort(S,S+3);
    if(S[0]=='a'&&S[1]=='b'&&S[2]=='c')cout << "Yes" << endl;
    else cout << "No" << endl;
}
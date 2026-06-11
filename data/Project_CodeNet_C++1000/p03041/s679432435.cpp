#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    string S;
    cin >> N >> K >> S;
    if(S[K-1]=='A')S.replace(K-1,1,"a");
    else if(S[K-1]=='B')S.replace(K-1,1,"b");
    else if(S[K-1]=='C')S.replace(K-1,1,"c");
    cout << S << endl;
    
}
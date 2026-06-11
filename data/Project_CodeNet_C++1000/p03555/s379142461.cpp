#include<bits/stdc++.h>
using namespace std;

int main(){
    string S,C;
    cin >> S >> C;
    if(S[2] != C[0]){
        cout << "NO" << '\n';
    }else if(S[1] != C[1]){
        cout << "NO" << '\n';
    }else if(S[0] != C[2]){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
    }
    return 0;
}
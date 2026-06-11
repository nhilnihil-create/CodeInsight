#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    string S;
    cin >> S;
    long long ans = 0;
    long long cont = 0;
    for(long long i = 0; i < S.size();i++){
        if(S[i]=='W'){
            ans += cont;
        }else{
            cont++;
        }
    }
    cout << ans <<endl;
}

    
    


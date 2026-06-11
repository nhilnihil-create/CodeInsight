#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    string T = "AKIHABARA";
    int ptr = 0;
    string ans = "YES";
    for(int i = 0; i < T.size(); i++){
        //cout << T[i] << " "<< S[ptr] << endl;
        
        
        if(T[i] == S[ptr])ptr++;
        else if(T[i] == 'A') continue;
        else ans = "NO";
        
        
    }
    
    if(ptr != S.size())ans = "NO";
    
    cout << ans << endl;
    
}

#include<bits/stdc++.h>
using namespace std;

bool f(char c){
    return c == 'A' || c == 'C' || c == 'G' || c == 'T';
}

int main(){
    int ans = 0;
    string S;
    cin >> S;
    for(int i = 0; i < S.size(); ++i){
        int buf = 0;
        for(int j = i; j < S.size(); ++j){
            if(f(S[j])) ++buf;
            else break;
        }
        ans = max(ans, buf);
    }
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

string S;

int main(){
    cin >> S;
    long long ans = 0, buf = 0;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] == 'B') ++buf;
        else if(S[i] == 'W') ans += buf;
    }
    cout << ans << endl;
    return 0;
}
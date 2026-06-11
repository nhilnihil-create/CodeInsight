#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    string S;
    cin >> S;
    ll cnt = 0;
    if(S[0] != 'A'){
        cout << "WA" << endl;
        return 0;
    }
    for(int i = 2; i < S.size() - 1; i++){
        if(S[i] == 'C') cnt++;
    }
    if(cnt != 1){
        cout << "WA" << endl;
        return 0;
    }  

    for(int i = 0; i < S.size() ; i++){
        if(0 >  S[i] - 'a' && S[i] - 'a' >= -32) cnt++;
    }

    if(cnt == 3)  cout << "AC" << endl;
    else cout << "WA" << endl;

}

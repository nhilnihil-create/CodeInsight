#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int cnt = 0;
    if(S[0] == 'o'){
        cnt++;
    }
    if(S[1] == 'o'){
        cnt++;
    }
    if(S[2] == 'o'){
        cnt++;
    }
    cout << 700+cnt*100 << endl;
}

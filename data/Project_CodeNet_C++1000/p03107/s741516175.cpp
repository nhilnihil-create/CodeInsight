#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int ao=0;
    int aka=0;

    for(int i=0; i<S.size(); i++){
        if(S[i] == '1') ao++;
        else aka++;
    }

    cout << 2* min(ao, aka) << endl;
}
// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S,T;
    cin >> S >> T;
    
    string roS,laS;
    for(int i=0; i<(int)S.size(); i++){
        if(S == T){
            cout << "Yes" << endl;
            return 0;
        }
        laS = S.at((int)S.size()-1);
        roS = S.erase((int)S.size()-1,1);
        S = laS + roS;
    }
    cout << "No" << endl;
}


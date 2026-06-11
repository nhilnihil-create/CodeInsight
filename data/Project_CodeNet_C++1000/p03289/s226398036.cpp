#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S.at(0) == 'A') {
        int cnt = 0;
    
        for (int i=2;i<S.size()-1;i++) {
            if (S.at(i) == 'C') {
                cnt++;
                S.at(i) = tolower(S.at(i));
        }
        if(cnt == 1) {
            for (int j=1;j<S.size();j++){
                if (!islower(S.at(j))) break;
                if (j == S.size()-1) {
                    cout << "AC" << endl;
                    return 0;
                }
            }
        }
    }
    }
    cout << "WA" << endl;
}

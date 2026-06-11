#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    int temp = 0;
    bool last = 0;

    for(int i = 0; i < S.size(); i++) {
        if(S.at(i) == 'A' || S.at(i) == 'G' || S.at(i) == 'C' || S.at(i) == 'T') {
            temp++;
            ans = max(ans,temp);
            
            S.at(i) = '1';
        } else {
            temp = 0;
            S.at(i) = '0';
        }
    }
    cout << ans << endl;
    for(int i = 0; 0; i++) {
        if(S.at(i)) {
            
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int ans = 0;

    for(int i = 0; i < S.size(); i++) {
        if(S.at(i) == '0')ans++;
    }
    
    cout << 2*min(ans,((int)S.size() - ans)) << endl;

    return 0;
}
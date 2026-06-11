#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int zero = 0, one = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == '0') zero++;
        else one++;
    }
    cout << min(zero, one) * 2 << endl;
}
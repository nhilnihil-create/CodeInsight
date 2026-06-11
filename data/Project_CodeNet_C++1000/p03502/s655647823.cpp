#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    vector<int> Sint(S.size());
    for (int i = 0; i < S.size(); i++) {
        Sint.at(i) = S.at(i) - '0';
    }
    int keta = 0;
    for (int i = 0; i < S.size(); i++) keta += Sint.at(i);
    vector<int> Smod(S.size());
    int m = 1;
    for (int i = S.size() - 1; i >= 0; i--) {
        Smod.at(i) = m;
        m = (m * 10) % keta;
    }
    ll sum = 0;
    for (int i = 0; i < S.size(); i++) {
        sum += (Sint.at(i) * Smod.at(i)) % keta;
        sum %= keta;
    }
    if (sum % keta == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

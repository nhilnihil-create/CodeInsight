#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int cnt = 700;
    if (S.at(0) == 'o') {
        cnt = cnt + 100;
    }
    if (S.at(1) == 'o') {
        cnt = cnt + 100;
    }
    if (S.at(2) == 'o') {
        cnt = cnt + 100;
    }
    cout << cnt << endl;
}

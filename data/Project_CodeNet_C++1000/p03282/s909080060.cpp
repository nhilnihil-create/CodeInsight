#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll gsc = (1e15)*5;

int main() {
    string S;
    ll K;
    cin >> S >> K;
    int now = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S.at(i) != '1') {
            //cout << i << endl;
            now = i;
            break;
        }
    }
    //cout << now << endl;
    if(now < K) {//1を超える時
        //cout << "##" << endl;
        cout << S.at((now != 0)*(now)*(now < S.size())) << endl;
    } else {//1を超えない時
        cout << 1 << endl;
    }



    return 0;
}
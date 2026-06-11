#include <bits/stdc++.h>
using namespace std;

bool isVacantRange(int i, string s, pair<int, string> LR) {
    if((i - LR.first)%2 == 0) {
        if(s == LR.second) return false;
        else return true;
    } else {
        if(s != LR.second) return false;
        else return true; 
    }
}

int main() { 
    int n;
    cin >> n;
    pair<int, string> L = {0, ""}, R = {n-1, ""};
    cout << L.first << endl;
    cin >> L.second;
    if(L.second == "Vacant") return 0;
    cout << R.first << endl;
    cin >> R.second;
    if(R.second == "Vacant") return 0;
    string s;
    while(1) {
        int i = (R.first + L.first)/2;
        cout << i << endl;
        cin >> s;
        if(s == "Vacant") return 0;
        if(isVacantRange(i, s, L)) {
            R = make_pair(i, s);
        } else {
            L = make_pair(i, s);
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int thr = 753;

int main(){

    string S;
    cin >> S;

    string buf;
    int temp, diff, diff_min = 1e5;

    // use stoi
    for (int i=0; i<S.size()-2; i++){
        buf = S.at(i);
        buf += S.at(i+1);
        buf += S.at(i+2);
        temp = stoi(buf);
        diff = abs(thr - temp);
        diff_min = min(diff_min, diff);
    }

    cout << diff_min << endl;
    return 0;
}
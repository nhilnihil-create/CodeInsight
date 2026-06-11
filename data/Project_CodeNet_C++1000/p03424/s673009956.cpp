//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
    int N;
    cin >> N;
    string S;
    vector<string> vec;
    bool same;
    for (int i = 0; i < N; i++) {
        cin >> S;
        same = false;
        for (int j = 0; j < vec.size(); j++) {
            if (vec.at(j) == S) {
                same = true;
                break;
            }
        }
        if (!same) {
            vec.push_back(S);
        }
    }
    if (vec.size() == 3) {
        cout << "Three" << endl;
    }
    else if (vec.size() == 4) {
        cout << "Four" << endl;
    }
}

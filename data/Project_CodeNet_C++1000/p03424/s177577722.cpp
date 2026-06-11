#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
    int N;
    cin >> N;
    string S;
    vector<string> vec = { "A" };
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < vec.size(); j++) {
            if (vec.at(j) == S) {
                break;
            }
            else if (vec.at(j) != S && j + 1 < vec.size()) {
                continue;
            }
            else if (vec.at(j) != S && j + 1 == vec.size()) {
                vec.push_back(S);
            }
        }
    }
    debug(vec.size());
    for (int j = 0; j < vec.size(); j++){
        debug(vec[j]);
    }
    
    vec.pop_back();
    if (vec.size() == 3) {
        cout << "Three" << endl;
    }
    else if (vec.size() == 4) {
        cout << "Four" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string>W(N);
    set<string>Set;
    for(int i = 0; i < N; i++) { 
        cin >> W[i];
        Set.insert(W[i]);
    }
    if(Set.size() != N) {
        cout << "No" << endl;
        return 0;
    }
    char usiro = W[0][W[0].size()-1];
    for(int i = 1; i < N; i++) {
        if(usiro != W[i][0]) {
            cout << "No" << endl;
            return 0;
        }
        usiro = W[i][W[i].size()-1];
    }
    cout << "Yes" << endl;
}
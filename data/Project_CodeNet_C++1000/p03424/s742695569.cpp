#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i=0;i<N;i++) {
        cin >> S.at(i);
    }
    
    bool Y = false;
    for (int i=0;i<N;i++) {
        if(S.at(i) == "Y") {
            Y = true;
            break;
        }
    }
    if (Y == true) {
        cout << "Four" << endl;
    }
    else {
        cout << "Three" << endl;
    }
}
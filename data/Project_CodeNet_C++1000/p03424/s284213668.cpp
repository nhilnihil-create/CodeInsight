#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    bool b=0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> S;
        if (S=="Y") {
            cout << "Four" << endl;
            b=1;
            break;
        }
    }
    if (!b){
        cout << "Three" << endl;
    }
}
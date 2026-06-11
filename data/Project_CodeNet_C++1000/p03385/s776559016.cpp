#include<bits/stdc++.h>

using namespace std;

int main () {

    string S;
    cin >> S;

    if(S == "abc") {
        cout << "Yes" << endl;
        return 0;
    }
    if(S == "acb") {
        cout << "Yes" << endl;
        return 0;
    }
    if(S == "bac") {
        cout << "Yes" << endl;
        return 0;
    }
    if(S == "bca") {
        cout << "Yes" << endl;
        return 0;
    }
    if(S == "cab") {
        cout << "Yes" << endl;
        return 0;
    }
    if(S == "cba") {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
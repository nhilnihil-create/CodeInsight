#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >>n;
    vector<string> w;
    string ret = "Yes", tmp;
    char last_c;

    // first one
    cin >> tmp;
    w.push_back(tmp);
    last_c = tmp.at(tmp.size()-1);

    // main
    for (int i = 1; i < n; i++) {
        cin >> tmp;

        if ( tmp.at(0) != last_c ) {
            ret = "No";
        }

        // double check
        if ( find(w.begin(), w.end(), tmp) != w.end() ) {
            ret = "No";
        }

        // good word
        last_c = tmp.at(tmp.size()-1);
        w.push_back(tmp);
    }
    cout << ret << endl;
    return 0;
}
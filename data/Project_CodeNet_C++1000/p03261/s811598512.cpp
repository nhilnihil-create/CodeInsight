#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    string w[n];
    vector<string> v;
    cin >> w[0];
    v.push_back(w[0]);
    for (int i=1; i<n; i++) {
        cin >> w[i];
        if(w[i][0] != w[i-1][w[i-1].size()-1]) {
            cout << "No" << endl;
            return 0;
        } else if (find(v.begin(), v.end(), w[i]) != v.end()) {
            cout << "No" << endl;
            return 0;
        } else {
            v.push_back(w[i]);
        }
    }
    cout << "Yes" << endl;
}
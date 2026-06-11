#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<string> w(n);
    set<string> s;
    for(int i = 0; i< n; ++i) {
        cin >> w[i];
        s.insert(w[i]);
    }
    if(s.size() != n) {
        cout << "No" << endl;
        return 0;
    }
    char start = w[0].back();
    for(int i = 1; i < n; ++i) {
        if(w[i][0] != start) {
            cout << "No" << endl;
            return 0;
        }
        start = w[i].back();
    }
    cout << "Yes" << endl;
    return 0;
}

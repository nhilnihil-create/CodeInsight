#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    set<string>v;

    for(int i = 0; i < s.size(); i++) {
        for (int j = 1; j<=min(k, int(s.size())); j++) {
            v.insert(s.substr(i, j));
        }
    }
    int c = 1;
    for (auto i = v.begin(); i != v.end(); i++) {
        if(c == k) {
            cout << *i << endl;
            return 0;
        }
        c++;
    }
    return 0;
}

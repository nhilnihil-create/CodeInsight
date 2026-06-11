#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> blue(n);
    set<string> bcard;
    for (int i = 0; i < n; i++) {
        cin >> blue[i];
        bcard.insert(blue[i]);
    }
    int m;
    cin >> m;
    vector<string> red(m);
    for (int i = 0; i < m; i++) {
        cin >> red[i];
    }

    int ans = 0;
    for(auto s : bcard){
        int buf = 0;
        for (string t: blue) {
            if (t == s) buf++;
        }
        for (string t: red) {
            if (t == s) buf--;
        }
        if(ans < buf){
            ans = buf;
        }
    }

    cout << ans << endl;
}


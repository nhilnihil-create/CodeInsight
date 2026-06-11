#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    vector<string> blue(n);
    for (int i=0; i<n; i++) {
        cin >> blue.at(i);
    }
    
    cin >> m;
    vector<string> red(m);
    for (int i=0; i<m; i++) {
        cin >> red.at(i);
    }
    
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        int counter = 0;
        string text = blue.at(i);
        for (int j=0; j<n; j++) {
            if (text == blue.at(j)) {
                counter++;
            }
        }
        for (int j=0; j<m; j++) {
            if (text == red.at(j)) {
                counter--;
            }
        }
        ans = max(ans, counter);
    }
    cout << ans << endl;
}
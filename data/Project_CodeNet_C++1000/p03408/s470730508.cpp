#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    int scount = 0;
    int smax = 0;
    int tcount = 0;
    
    cin >> n;
    vector<string> s(n);
    
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }
    
    cin >> m;
    vector<string> t(m);
    
    for (int i = 0; i < m; i++) {
        cin >> t.at(i);
    }

    for (int i = 0; i < n; i++) {
        scount = count(s.begin(), s.end(), s.at(i));
        tcount = count(t.begin(), t.end(), s.at(i));

        if (smax < scount - tcount) {
            smax = scount - tcount;
        }
    }
    cout << smax << endl;
    
}
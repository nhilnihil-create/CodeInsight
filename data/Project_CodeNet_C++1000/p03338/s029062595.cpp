#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0, t;
    for (int i=1; i<n; i++) {
        t = 0;
        vector<int> c(26, 0);
        for (int j=0; j<i; j++) {
            for (int k=i; k<n; k++) {
                if (c[s[j]-'a'] == 0 &&s[j] == s[k]) {
                    c[s[j]-'a'] = 1;
                    t++;
                    break;
                }
            }
        }
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<char> t(Q), d(Q);
    for (int i = 0; i < Q; i++) cin >> t[i] >> d[i];
    
    int l = -1;
    int r = N;
    while (r - l > 1) {
        int c = (l+r)/2;
        bool lerase = false;
        int pos = c;
        for (int i = 0; i < Q; i++) {
            if (t[i] == s[pos]) {
                if (d[i] == 'L') pos--;
                else pos++;
            }
            if (pos < 0) {
                lerase = true;
                break;
            }
            if (pos >= N) break;
        }
        if (lerase) l = c;
        else r = c;
    }
    int ansl = r;
    
    l = -1;
    r = N;
    while (r - l > 1) {
        int c = (l+r)/2;
        bool rerase = false;
        int pos = c;
        for (int i = 0; i < Q; i++) {
            if (t[i] == s[pos]) {
                if (d[i] == 'L') pos--;
                else pos++;
            }
            if (pos >= N) {
                rerase = true;
                break;
            }
            if (pos < 0) break;
        }
        if (rerase) r = c;
        else l = c;
    }
    int ansr = r;
    cout << ansr-ansl << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() { 
    string s;
    int a[26] = {0};
    cin >> s;
    int ssize = s.size();
    if(s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << '\n'; 
        return 0;
    }
    if(ssize != 26) {
        for(int i = 0; i < ssize; ++i) {
            a[s[i] - 'a'] = 1;
        }
        for(int i = 0; i < 26; ++i) {
            if(a[i] == 0) {
                s += (char)(i + 'a');
                break;
            }
        }
    } else {
        for(int i = 25; i >= 1; --i) {
            if(s[i-1] < s[i]) {
                for(int j = 0; j < i; ++j) {
                    a[s[j] - 'a'] = 1;
                }
                char ss = s[i-1];
                s = s.substr(0, i-1);
                for(int j = 0; j < 26; ++j) {
                    if(a[j] == 0 && (char)(j + 'a') > ss) {
                        s += (char)(j + 'a');
                        break;
                    }
                }
                break;
            }
        }
    }
    cout << s << '\n';
    return 0;
}

#include<bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define sloop(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int mx = INT_MIN;
    loop(mid, n) {
        int count = 0;
        set<char> s1, s2;
        loop(i, mid) {
            s1.insert(s[i]);
        }
        sloop(i, mid, n) {
            if(s1.find(s[i]) != s1.end() && s2.find(s[i]) == s2.end()) {
                count++;
                s2.insert(s[i]);
            }
        }
        mx = max(mx, count);
    }
    cout << mx << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100010; 
int n, sz[N]; string s; 
int main() {
    cin >> s; 
    n = s.length();
    string s1 = s.substr(0, n-1); 
    if (!count(s1.begin(), s1.end(), '1')) return puts("-1"), 0;
    string t = s1; reverse(t.begin(), t.end());
    if (t != s1) return puts("-1"), 0;
    if (s[n - 1] == '1' || s[0] == '0') return puts("-1"), 0;

    vector <int> pos; 
    for (int i = 0; i < n; i++) if (s[i] == '1')
        pos.push_back(i + 1);

    int ps = pos.size() + 2;
    int nowadd = 1;

    for (int i = 0; i < n; i++) if (s[i] == '1') {
        sz[nowadd] = sz[nowadd - 1] + 1;

        while (sz[nowadd] < i + 1) sz[nowadd]++, cout << nowadd << " " << (ps++) << endl;
        cout << nowadd << " " << nowadd + 1 << endl;
        ++nowadd;  
    }


    return 0; 
}
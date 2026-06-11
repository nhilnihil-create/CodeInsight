#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s; cin >> s;
    int n = s.size();
    int nin = n;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            int cur = max(i, n - i);
            nin = min(cur, nin);
        }
    }
    cout << nin << endl;
}
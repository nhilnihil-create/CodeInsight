#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s, t; cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(i != n - 1 && s[i] == 'B' && s[i + 1] == 'C') {
            t.push_back('D');i++;
        } else {
            t.push_back(s[i]);
        }
    }
    n = t.size();
    vector<string> str;

    for(int i = 0; i < n; i++) {
        int j = i;
        while((t[j] == 'A' || t[j] == 'D') && j < n) {
            j++;
        } 
        if(i == j)continue;
        str.push_back(t.substr(i, j - i));
        i = j;
    }

    ll cnt = 0;

    for(auto s : str) {
        int cur = 0;
        for(auto j : s) {
            if(j == 'D')cnt += cur;
            else cur++;
        }
    }
    cout << cnt << endl;
}
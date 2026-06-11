#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s; cin >> s;
    set<string> st;
    int n = s.size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 5 && i + j <= n; j++) st.insert(s.substr(i, j));
    }
    int k; cin >> k;
    string ans;
    for(auto i : st) {
        k--;
        ans = i;
        if(!k)break;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    string s,t;cin >> s >> t;
    vector<vector<int>> a(26),b(26);
    for(int i = 0; i < s.size(); i++) {
        a[(int)s[i]-97].push_back(i);
    }
    for(int i = 0; i < s.size(); i++) {
        b[(int)t[i]-97].push_back(i);
    }

    bool ans=true;
    for(int i = 0; i < 26; i++) {
        if(b[i].size()==0) continue;
        bool y=false;
        for(int j = 0; j < 26; j++) {
            if(b[i]==a[j]) y=true;
        }
        if(!y) ans=false;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
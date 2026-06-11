#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s,t;

    map<int,int> mps;
    map<int,int> mpt;
    cin >> s >> t;
    for(int i=0;i<s.size();i++) {
        mps[s[i]-'a']++;
    }
    for(int i=0;i<t.size();i++) {
        mpt[t[i]-'a']++;
    }
    // 文字列中に無い文字に入れ替えるパターンは考慮不要

    vector<int> sv;
    vector<int> tv;
    for(auto m:mps) {
        sv.push_back(m.second);
    }
    for(auto m:mpt) {
        tv.push_back(m.second);
    }

    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end());

    if(sv == tv) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;

}

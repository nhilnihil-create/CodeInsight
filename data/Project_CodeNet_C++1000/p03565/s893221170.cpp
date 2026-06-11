#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    priority_queue<string, vector<string>, greater<string>> can;
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        bool flag = true;
        for(int j = 0; j < t.size(); j++){
            if(s[i+j] != t[j] && s[i+j] != '?') flag = false;
        }
        if(!flag) continue;
        string tmp = s;
        copy(begin(t), end(t), begin(tmp) + i);
        replace(begin(tmp), end(tmp), '?', 'a');
        can.push(tmp);
    }

    cout << (can.empty() ? "UNRESTORABLE" : can.top()) << endl;
    return 0;
}
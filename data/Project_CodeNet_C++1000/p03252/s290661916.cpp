#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s, t;
    cin >> s >> t;
    map<char, set<char>> ss, tt;
    for(int i = 0; i < s.size(); i++){
        tt[t[i]].insert(s[i]);
        ss[s[i]].insert(t[i]);
    }
    bool flag = true;
    for(auto c : s){
        if(ss[c].size() != 1){
            flag = false;
            break;
        }
        char opponent = *ss[c].begin();
        if(tt[opponent].size() != 1){
            flag = false;
            break;
        }
        if(*tt[opponent].begin() != c){
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes\n" : "No\n");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define PI acos(-1)

int main(){
    string s,t;
    cin >> s >> t;
    vector<vector<int>> alfs(26),alft(26);

    for(int i = 0;i < (int)s.size();i++){
        alfs[s[i] - 'a'].push_back(i);
        alft[t[i] - 'a'].push_back(i);
    }

    for(int i = 0;i < (int)alfs.size();i++){
        for(int j = 0;j < alfs[i].size();j++){
            s[alfs[i][j]] = alfs[i].size();
        }
        for(int j = 0;j < alft[i].size();j++){
            t[alft[i][j]] = alft[i].size();
        }
    }
    cout << (s == t ? "Yes":"No") << endl;
}

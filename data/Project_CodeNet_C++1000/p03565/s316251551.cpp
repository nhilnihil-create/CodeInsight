#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s,t; cin >> s >> t;
    vector<string> ans;
    int l = s.size() - t.size() + 1;
    for(int i = 0; i < max(l,0); i++){
        string tmp = s;
        for(int j = 0; j < t.size(); j++){
            if(i + j > s.size() - 1)break;
            if(tmp[i+j] == t[j] || tmp[i+j] == '?')tmp[i+j] = t[j];
            else break;
            if(j == t.size() - 1){
                for(int k = 0; k < tmp.size(); k++){
                    if(tmp[k] == '?')tmp[k] = 'a';
                }
                ans.push_back(tmp);
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()!=0)cout << ans[0] << endl;
    else cout << "UNRESTORABLE" << endl;
    
    
    
}

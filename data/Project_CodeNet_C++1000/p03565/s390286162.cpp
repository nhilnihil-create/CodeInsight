#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    string T;
    cin >> S >> T;
    if(S.size() < T.size()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    vector<string>ans;
    bool flag = false;
    for(int i = 0; i <= S.size()-T.size(); i++) {
        bool ok = true;
        int X = i;
        for(int j = 0; j < T.size(); j++) {
            if(S[X+j] != '?' && T[j] != S[X+j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            flag = true;
            string cnt = "";
            for(int k = 0; k < S.size(); k++) {
                if(k == X) {
                    cnt+=T;
                    k+=T.size()-1;
                }
                else {
                    if(S[k] == '?') {
                        cnt+='a';
                    }
                    else {
                        cnt+=S[k];
                    }
                }
            }
            ans.push_back(cnt);
        }
    }
    if(flag) {
        sort(ans.begin(),ans.end());
        cout << ans[0] << endl;
    }
    else {
        cout << "UNRESTORABLE" << endl;
    }
}
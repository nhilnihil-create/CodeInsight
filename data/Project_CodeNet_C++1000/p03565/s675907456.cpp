#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    string T; cin >> T;
    int s = S.size();
    int t = T.size();
    vector<string> ans;
    for(int i = 0; i < s - t + 1; i++){
        string U = S;
        bool flag = false;
        //cout << i << endl;
        for(int j = 0; j < t; j++){
            
            if(U[i+j]==T[j] || U[i+j] == '?')U[i+j] = T[j];
            else {flag = true;break;}
        }
        //cout << i << endl;
        if(flag)continue;
        for(int j = 0; j < s; j++){
            if(U[j]=='?')U[j] = 'a';
        }
        ans.push_back(U);
    }
    if(ans.size()==0){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    sort(ans.begin(),ans.end());
    cout << ans[0] << endl;
    return 0;
}

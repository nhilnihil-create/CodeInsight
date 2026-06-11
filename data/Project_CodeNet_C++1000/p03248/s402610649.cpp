#include <bits/stdc++.h>
using namespace std;

void fail(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    string S;
    cin >> S;
    int N = S.size();
    S = "0" + S;
    if(S[1] == '0') fail();
    for(int i=1; i<=N; i++) if(S[i] != S[N-i]) fail();

    vector<pair<int, int>> ans;
    int r = 1;
    for(int i=1; i<N; i++){
        if(S[i] == '1'){
            ans.emplace_back(r, i+1);
            r = i+1;
        }else{
            ans.emplace_back(r, i+1);
        }
    }
    for(auto& p : ans) cout << p.first << " " << p.second << endl;
}
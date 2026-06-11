#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S; cin >> S;
    int K; cin >> K;
    set<string> st;
    for(char c = 'a'; c <= 'z'; ++c){
        for(int i = 0; i < S.size(); ++i){
            if(S[i] != c) continue;
            for(int j = 1; j <= K && i+j <= S.size(); ++j) {
               st.insert(S.substr(i, j));
            }
        }
        if(st.size() >= K) {
            int counter = 1;
            for(string s : st){
                if(counter == K) {
                    cout << s << '\n';
                    return 0;
                }
                counter++;
            }
        }
    }
    return 0;
}
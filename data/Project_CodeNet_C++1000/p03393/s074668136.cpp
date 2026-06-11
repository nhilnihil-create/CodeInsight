#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string S;
    cin >> S;
    if(S=="zyxwvutsrqponmlkjihgfedcba"){
        cout <<-1<<endl;
        return 0;
    }
    vector<bool> used(26,false);
    for(int i=0;i<S.size();i++){
        used[S[i]-'a'] = true;
    }
    for(int i=0;i<26;i++){
        if(!used[i]){
            char s = 'a' +i;
            cout << S+s << endl;
            return 0;
        }
    }
    
    for(int i=S.size()-2;i>=0;--i){
        if(S[i] < S[i+1]){
            int lastNum =26;
            for(int j=S.size()-1;j>i;--j){
                if(S[i] < S[j]){
                    lastNum = min(lastNum,S[j]-'a');
                }
            }
            string ans="";
            for(int j=0;j<i;j++){
                ans += S[j];
            }
            char s = 'a'+lastNum;
            ans += s;
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
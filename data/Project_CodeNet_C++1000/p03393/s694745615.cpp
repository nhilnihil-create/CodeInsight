#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;




int main() {
    string S; cin >> S;
    vector<int> v(26,0);
    for(int i=0;i<S.size();i++) v[S[i]-'a']++;
    if(S.size()!=26){
        for(int i=0;i<26;i++){
            if(v[i]==0){cout << S+char('a'+i) << endl;break;}
        }
    }else{
        bool quit=false;
        for(int i=25;i>=0;i--){
            char c = S[i];
            S = S.substr(0,i);
            for(int j=c-'a';j<26;j++){
                if(v[j]==0){
                    cout << S+char('a'+j) << endl;
                    quit=true; break;
                }
            }
            if(quit) break;
            v[c-'a']--;
            if(i==0) cout << -1 << endl;
        }
    }
}


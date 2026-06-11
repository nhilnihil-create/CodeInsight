#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    string S, S_; cin >> S; S_ = S;
    set<char> ST;
    for(auto ch : S) ST.insert(ch);
    
    for(int i = 0; i < 26; i++){
        char add = i+97;
        if(ST.find(add) == ST.end()){
            S_+=add;
            cout << S_ << endl;
            return 0;
        }
    }
 //cout << 1 << endl;
    for(int i = S.size()-1; i >=0; i--){
        char ch = S[i];
        //cout << S_ << endl;
        for(int j = (int)S[i]; j <= 122; j++){
            if(ST.find((char)j) == ST.end() && S[i] < j){
                S_[i] = j;
                cout << S_ << endl;
                return 0;
            }
        }
        S_.erase(i);
        ST.erase(ch);

    } 
    cout << -1 << endl;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    string s,t;
    cin >> s >> t;
    
    if(s.size()<t.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    
    //入れる場所があるのかどうか
    int fit=-1;
    for(int i=0; i<=s.size()-t.size(); i++){
        for(int j=0; j<t.size(); j++){
            if(s[i+j]=='?' || s[i+j]==t[j]){
                if(j == t.size() -1){
                    fit = max(fit,i);
                }
            }else{
                break;
            }
        }
    }
    // cout << fit << endl;
    
    // 不可能判定
    if(fit==-1){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    
    // 入れるべき場所にいれる
    for(int i=fit; i<t.size() + fit; i++){
        s[i] = t[i-fit];
    }
    // cout << s << endl;
    
    // ？をaに
    for(int i=0; i<s.size(); i++){
        if(s[i] == '?') s[i] = 'a';
    }
    cout << s << endl;
}

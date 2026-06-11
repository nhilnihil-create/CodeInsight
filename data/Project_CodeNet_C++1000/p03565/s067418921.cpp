#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll pow(ll n){
    if(n == 1) return 1;
    else return n*pow(n-1)%1000000007;
}

int main(){
    string s ,t;
    cin >> s >> t;
    if(t.size()>s.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    int start = -1;
    bool cont = true;
    for(int i = s.size() - t.size() ;i>=0;i--){
        for(int j = 0;j<t.size();j++){
            if(s[i+j]==t[j] || s[i+j]=='?'){
                if(j==t.size()-1){
                    cont = false;
                    start = i;
                    break;
                }
            }else break;
        }if(!cont) break;
    }

    if(start<0){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for(int i=0;i<s.size();i++){
        if(start <= i && i <= start + t.size() -1) cout << t[i-start];
        else if(s[i]=='?') cout <<'a' ;
        else cout << s[i];
    }
    cout << endl;
}
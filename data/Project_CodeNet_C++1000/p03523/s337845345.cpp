#include<bits/stdc++.h>
using namespace std;


int main(){
    string s; cin >> s;
    string ref = "AKIHABARA";
    int n=9;
    int s_p = 0;
    int s_len = s.size();
    for(int i=0; i<n; i++){
        if(ref[i]=='A'){
            if(s[s_p]=='A') s_p++;
        }
        else{
            if(ref[i]==s[s_p]) s_p++;
            else{
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if(s_p==s_len){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
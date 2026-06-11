#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int S[26]={},T[26]={};
    for(int i=0;i<s.size();i++){
        S[s[i]-'a']++;
        T[t[i]-'a']++;
    }
    sort(S,S+26);
    sort(T,T+26);
    for(int i=0;i<26;i++){
        if(S[i]!=T[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}

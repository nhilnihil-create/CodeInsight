#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int a[26]={};
    for(int i=0;i<s.size();i++) a[s[i]-'a']++;
    for(int i=0;i<26;i++){
        if(a[i]==0){
            cout << s+char(i+'a') << endl;
            return 0;
        }
    }
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    } 
    vector<int> elst(26);
    int i=25,flag = 1;
    while(0<i&&flag){
        elst[s[i]-'a']=1;
        s.erase(i);
        for(int j=s[i-1]-'a';j<26;j++){
            if(elst[j]){
                s[i-1]=j+'a';
                flag = 0;
                break;
            }    
        }
        i--;
    }
    cout << s << endl;
}
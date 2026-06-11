#include <bits/stdc++.h>
using namespace std;
string akiba = "AKIHABARA";
void dfs(string s, int x){
    if(x!=-1){
        s.insert(x, "A");
    }
    if(s.size()==9){
        if(akiba==s) {cout<<"YES"<<endl; exit(0);}
        return ;
    } 
    for(int i=0;i<=s.size();i++){
        dfs(s, i);
    }
    return ;
}
int main(void){
    string s; cin>>s;
    if(s.size()>9) {cout<<"NO"<<endl; return 0;}
    dfs(s, -1);
    cout<<"NO"<<endl;
}

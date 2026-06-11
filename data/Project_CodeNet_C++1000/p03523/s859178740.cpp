#include<bits/stdc++.h>
using namespace std;
void dfs(int x,string a,string b,string c){
    if(x==a.length()){
        if(b==c){puts("YES");exit(0);}
        else return ;
    }
    if(a[x]=='A')dfs(x+1,a,b,c);
    dfs(x+1,a,b,c+a[x]);
}
int main(){
    string s,t="AKIHABARA";
    cin>>s;
    dfs(0,t,s,"");
    puts("NO");
}
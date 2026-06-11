#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int h,w,n;scanf("%d%d%d",&h,&w,&n);
    int sr,sc;scanf("%d%d",&sr,&sc);
    string s,t;cin>>s>>t;
    bool flag=false;
    int x=sr,y=sc;
    //L R U D
    for(int i=0;i<s.size();i++){
        if(s[i]=='L'){
            y--;
        }
        if(y==0) flag=true;
        if(t[i]=='R'&&y<w){
            y++;
        }
    }
    x=sr;y=sc;
    for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
            y++;
        }
        if(y>w) flag=true;
        if(t[i]=='L'&&y>1){
            y--;
        }
    }x=sr;y=sc;
    for(int i=0;i<s.size();i++){
        if(s[i]=='U'){
            x--;
        }
        if(x==0) flag=true;
        if(t[i]=='D'&&x<h){
            x++;
        }
    }x=sr;y=sc;
    for(int i=0;i<s.size();i++){
        if(s[i]=='D'){
            x++;
        }
        if(x>h) flag=true;
        if(t[i]=='U'&&x>1){
            x--;
        }
    }
    if(flag) puts("NO");
    else puts("YES");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w,black=0;
    cin>>h>>w;
    vector<vector<char>>s(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s[i][j];
            if(s[i][j]=='#')black++;
        }
    }
    queue<tuple<int,int,int>>q;
    q.push(make_tuple(0,0,1));
    int check[h][w]={};
    check[0][0]=1;
    while(q.size()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int d=get<2>(q.front());
        q.pop();
        if(x==h-1 && y==w-1){
            cout<<h*w-black-d<<endl;
            return 0;
        }
        if(x && s[x-1][y]=='.' && check[x-1][y]==0){
            q.push(make_tuple(x-1,y,d+1));
            check[x-1][y]=1;
        }
        if(y && s[x][y-1]=='.' && check[x][y-1]==0){
            q.push(make_tuple(x,y-1,d+1));
            check[x][y-1]=1;
        }
        if(x<h-1 && s[x+1][y]=='.' && check[x+1][y]==0){
            q.push(make_tuple(x+1,y,d+1));
            check[x+1][y]=1;
        }
        if(y<w-1 && s[x][y+1]=='.' && check[x][y+1]==0){
            q.push(make_tuple(x,y+1,d+1));
            check[x][y+1]=1;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
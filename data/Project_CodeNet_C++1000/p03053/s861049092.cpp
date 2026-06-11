#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>a(h,vector<char>(w));
    queue<tuple<int,int,int>>q;
    int black=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                q.push(make_tuple(i,j,1));
                black++;
            }
        }
    }
    int m=0;
    while(black<h*w){
        int x=get<0>(q.front()),y=get<1>(q.front()),d=get<2>(q.front());
        q.pop();
        m=max(m,d);
        if(x>0 && a[x-1][y]=='.'){
            a[x-1][y]='#';
            q.push(make_tuple(x-1,y,d+1));
            black++;
        }
        if(x<h-1 && a[x+1][y]=='.'){
            a[x+1][y]='#';
            q.push(make_tuple(x+1,y,d+1));
            black++;
        }
        if(y>0 && a[x][y-1]=='.'){
            a[x][y-1]='#';
            q.push(make_tuple(x,y-1,d+1));
            black++;
        }
        if(y<w-1 && a[x][y+1]=='.'){
            a[x][y+1]='#';
            q.push(make_tuple(x,y+1,d+1));
            black++;
        }
    }
    cout<<m<<endl;
    return 0;
}
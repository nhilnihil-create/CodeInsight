#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    int a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)cin>>a[i][j];
    }
    vector<vector<int>>move;
    bool b=false;
    for(int i=0;i<h;i++){
        if(i%2==0){
            for(int j=0;j<w;j++){
                if(a[i][j]%2){
                    if(b)b=false;
                    else b=true;
                }
                if(b){
                    if(j<w-1)move.push_back({i+1,j+1,i+1,j+2});
                    else if(i<h-1)move.push_back({i+1,j+1,i+2,j+1});
                }
            }
        }
        else{
            for(int j=w-1;j>=0;j--){
                if(a[i][j]%2){
                    if(b)b=false;
                    else b=true;
                }
                if(b){
                    if(j>0)move.push_back({i+1,j+1,i+1,j});
                    else if(i<h-1)move.push_back({i+1,j+1,i+2,j+1});
                }
            }
        }
    }
    cout<<move.size()<<endl;
    for(int i=0;i<move.size();i++){
            cout<<move[i][0]<<" "<<move[i][1]<<" "<<move[i][2]<<" "<<move[i][3]<<endl;
        }
    return 0;
}
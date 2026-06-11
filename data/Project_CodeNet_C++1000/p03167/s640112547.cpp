#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int maxValue = 1e5 + 5 , mod = 1e9 + 7;

int main(){
    int h , w;
    cin>>h>>w;
    string s[h];
    int paths[h][w];
    bool visited[h][w];
    for(int i = 0; i < h; i++){
        cin>>s[i];
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            paths[i][j] = 0;
            visited[i][j] = false;
        }
    }
    queue<pair<int , int> >q;
    q.push({0 , 0});
    paths[0][0] = 1;
    
    while(q.size()){
        pair<int , int>temp = q.front();
        q.pop();
        int tempH = temp.first , tempW = temp.second;
        if(tempH + 1 < h && tempW < w){
            if(s[tempH + 1][tempW] == '.'){
                paths[tempH + 1][tempW] = (paths[tempH + 1][tempW] + paths[tempH][tempW])%mod;
                if(!visited[tempH + 1][tempW]){
                    q.push({tempH + 1 , tempW});
                    visited[tempH + 1][tempW] = 1;
                }
            }
        }
        if(tempW + 1 < w && tempH < h){
            if(s[tempH][tempW + 1] == '.'){
                paths[tempH][tempW + 1] = (paths[tempH][tempW + 1] + paths[tempH][tempW])%mod;
                if(!visited[tempH][tempW + 1]){
                    q.push({tempH , tempW + 1});
                    visited[tempH][tempW + 1] = 1;
                }
            }
        }
    }
    cout<<paths[h - 1][w - 1];
}
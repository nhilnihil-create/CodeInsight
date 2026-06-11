#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(void){
    
    int H,W;
    cin >> H >>W;
    string S[H];
    
    for(int i = 0; i < H;i++) cin >> S[i];
    
    
    queue<pair<int,int>> queue;
    int F[H][W];
    
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++ ){
            F[i][j] = 0;
            if(S[i][j]=='#'){
                F[i][j] = 1;
                queue.push(make_pair(i,j));
            }
        }
    }
    
    
    int h,w;
    int cont = 0;
    bool flag = true;
    while(queue.size()){
        
        flag = false;
        // for(int i = 0; i < H;i++){
        //     for(int j = 0; j < W;j++ ){
        //         cout << S[i][j]<<" ";
                
        //         if(S[i][j]=='.') flag = true; 
        //     }
        //     cout << endl;
        // }
        // cout <<"------------------------"<<endl;

            
        //cout << h <<" "<< w << endl;
        h = queue.front().first;
        w = queue.front().second;
        cont = F[h][w];
            
        queue.pop();
            
        if(h < H - 1){
            if(S[h+1][w]!='#'){
                queue.push(make_pair(h+1,w));
                S[h+1][w]='#';
                F[h+1][w]=cont+1;
            }
        }
            
        if(0 < h){
            if(S[h-1][w]!='#'){
                queue.push(make_pair(h-1,w));
                S[h-1][w]='#';
                F[h-1][w]=cont+1;
            }
        }
            
        if(w < W - 1){
            if(S[h][w+1]!='#'){
                queue.push(make_pair(h,w+1));
                S[h][w+1]='#';
                F[h][w+1]=cont+1;
            }
        }
            
        if(0 < w){
            if(S[h][w-1]!='#'){
                queue.push(make_pair(h,w-1));
                S[h][w-1]='#';
                F[h][w-1]=cont+1;
            }
        }
        

        
    }
    
    cout << cont -1  << endl;    
    
}

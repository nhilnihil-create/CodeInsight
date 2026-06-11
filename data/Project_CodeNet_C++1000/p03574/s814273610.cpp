#include <bits/stdc++.h>
using namespace std;
#define dout cout
#ifndef dout
#define //
#endif

int main(){
    char map[50+2][50+2];//vector忘れた、場合分け避けるために一周多く作ってる

    int H,W;
    cin>>H>>W;
    //dout<<"H:"<<H<<"W:"<<W<<"\n";
    char c;
    for(int i = 0; i < H; i++){//////////////入力
        for(int j=0; j<W; j++){
            cin>>c;
            if(c=='.'){//ドット
                map[i+1][j+1] = '0';
            }
            else{//爆弾
                map[i+1][j+1] = '#';
            }
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i+1][j+1] == '#'){///////爆弾なら周り8マスに+1する
                if(map[i+0][j+0] != '#') map[i+0][j+0]++;
                if(map[i+0][j+1] != '#') map[i+0][j+1]++;
                if(map[i+0][j+2] != '#') map[i+0][j+2]++;
                if(map[i+1][j+0] != '#') map[i+1][j+0]++;
                //map[i+1][j+1]
                if(map[i+1][j+2] != '#') map[i+1][j+2]++;
                if(map[i+2][j+0] != '#') map[i+2][j+0]++;
                if(map[i+2][j+1] != '#') map[i+2][j+1]++;
                if(map[i+2][j+2] != '#') map[i+2][j+2]++;
            }
        }
    }
    
    
   dout<<"\n\n";//////////////////////////////////////////
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout<<map[i+1][j+1];
        }
        cout<<'\n';
    }
}
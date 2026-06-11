#include <bits/stdc++.h>

using namespace std;

int main(){
    int H,W; cin >> H >> W;
    vector<vector<char>> s(H,vector<char>(W));

    int dw[4] ={1,0,-1,0};
    int dh[4] ={0,1,0,-1};
    bool can = true;

    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            cin >> s.at(h).at(w);
        }
    }

    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            if(s[h][w] == '#'){
                int flg = 0;
                for(int i=0; i<4; i++){
                    int nh = h+dh[i];
                    int nw = w+dw[i];
                    if(nh < 0 || nh >=H || nw <0 || nw>=W){flg++;}
                    else if(s[nh][nw] == '.') flg++;
                }
                if(flg == 4) can = false;
            }
        }
    }
    
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;


}
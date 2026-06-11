#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int H,W;
    cin >> H >> W;
    
    //フィールドとキュー
    vector<vector<char>> nurinuri(H,vector<char>(W));
    vector<vector<int>> step(H,vector<int>(W,-1));
    queue<pair<int,int>> que;
    
    //入力
    rep(i,H){
        rep(j,W){
            cin >> nurinuri[i][j];
            if(nurinuri[i][j] == '#'){
                que.push(pair(i,j));
                step[i][j] = 0;
            }
        }
    }
    
    vector<int> shui={-1,0,1};
    int ans=0;
    while(!que.empty()){
        auto q = que.front(); que.pop();
        int x=q.first, y=q.second;
        
        for(int i:shui){
            for(int j:shui){
                if(i*j != 0) continue;
                if(x+i<0 || x+i>=H || y+j<0 || y+j>=W) continue;
                if(step[x+i][y+j] != -1) continue;
                //if(nurinuri[x+i][y+j] == '#') continue;
                
                step[x+i][y+j] = step[x][y] + 1;
                ans = max(ans, step[x+i][y+j]);
                que.push(pair(x+i,y+j));
                
            }
        }
    }
    
    cout << ans << endl;
    
    /*
    rep(i,H){
        rep(j,W){
            cout << step[i][j] << " ";
            
        }
        cout << endl;
    }
    */
    
}

#include<bits/stdc++.h>
using namespace std;

//  四方向へのベクトル
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

int h,w,n;
//探索用
//bool seen[1000][1000];
int gh,gw,MAX=0;
long long sum=0;
int seen[2000][2000];

int bfs(const vector<string> &G,int Ncnt,int x,int y,queue <int> q){
   //x,yの順に格納
   q.push(x);
   q.push(y);
//    seen[y][x] = 0;

   while(true){
        int cc = q.front();
        q.pop();
        int rr = q.front();
        q.pop(); 
        
        //cout << "Q OF SIZE is "<<q.size() <<" next(" <<cc<<" "<<rr<<")"<<endl;
        for(int i=0;i<4;i++){
            int next_x = cc + dx[i];
            int next_y = rr + dy[i];
            //cout << next_x << " " <<next_y<<" "<<seen[next_y][next_x]<< endl;

            if(next_x<0 || next_x >=w || next_y<0 || next_y>=h) continue;
            if(seen[next_y][next_x] != -1) continue;
            if(G[next_y][next_x]  == '#') continue;

            //cout << "path" <<endl;
            

            q.push(next_x);
            q.push(next_y);
            
             seen[next_y][next_x] = seen[rr][cc] +1;
             //cout << next_x << " " << next_y << " "<<seen[next_y][next_x]<<endl;
             //cout <<"SIZE "<<q.size()<<" "<<G[next_y][next_x]<<endl;

             if(seen[next_y][next_x] > MAX) MAX = seen[next_y][next_x];
            //  if(G[next_y][next_x] - '0' == Ncnt){
            //      sum += seen[next_y][next_x];
            //      //cout <<seen[next_y][next_x]<<endl;
            //      //cout <<next_y<<" "<<next_x<<endl;
            //      memset(seen,-1,sizeof(seen));
            //      seen[next_y][next_x] = 0;
            //      while(q.size()!=2) q.pop();
                 
            //      //cout <<"a"<<Ncnt<<endl;
            //      Ncnt++;
            //      break;
            //  }
            // // cout<<seen[next_y][next_x] <<endl;

            //    dfs(G,cnt,next_x,next_y);
        }

        if(q.size() == 0) break;
   }

  return 0;
}

int main(){
    cin >> h>> w;
    int sh,sw;

    vector<string> G(h);
    for(int i=0;i<h;i++) cin >> G[i];

    queue <int> q;
    memset(seen,-1,sizeof(seen));
    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){
            if(G[i][k] == '#'){
                sh = i;
                sw = k;
                //　ループを抜ける
                q.push(sw);
                q.push(sh);
                seen[sh][sw] = 0;
            }
        }
    }

    
    //cout << seen[0][0] << endl;

    bfs(G,1,sw,sh,q);

    cout << MAX <<endl;
    return 0;
    
}


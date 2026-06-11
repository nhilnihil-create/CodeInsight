#include <bits/stdc++.h>
using namespace std;

int INF=1000000;
queue<pair<int,int> > que;
vector<int> dx(4,0),dy(4,0);

void bfs(vector<vector<char> > &map,vector<vector<int> > &d){
    pair<int,int> p;
    while(que.size()>0){
        p=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int nx=p.first+dx.at(i),ny=p.second+dy.at(i);
            if(0<=nx&&nx<map.size()&&0<=ny&&ny<map.at(0).size()&&map.at(nx).at(ny)!='#'&&d.at(nx).at(ny)==INF){
                pair<int,int> np;
                np.first=nx;
                np.second=ny;
                que.push(np);
                d.at(nx).at(ny)=d.at(p.first).at(p.second)+1;
            }
        }
    }
    return;
}
int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<char> > map(H,vector<char> (W));
    vector<vector<int> > d(H, vector<int>(W,INF));
    dx.at(0)=1;
    dx.at(2)=-1;
    dy.at(1)=1;
    dy.at(3)=-1;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>map.at(i).at(j);
            if(map.at(i).at(j)=='#'){
                pair<int,int> p;
                p.first=i;
                p.second=j;
                que.push(p);
                d.at(i).at(j)=0;
            }
        }
    }
    bfs(map,d);
    int fintime=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            fintime=max(d.at(i).at(j),fintime);
        }
    }
    cout<<fintime<<endl;
    
}
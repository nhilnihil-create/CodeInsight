#include<bits/stdc++.h>
using namespace std;
int main(){
    int H,W;
    cin>>H>>W;
    vector<string>G(H);
    int cnt=0;
    for(int i=0;i<H;i++)cin>>G[i];
    queue<pair<int,int>>que;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(G[i][j]=='#'){
                    que.push(make_pair(i,j));
                    cnt++;
                }
            }
        }
        int tmp=0;
        int ans=0;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!que.empty()){
            auto v=que.front();
            que.pop();
            cnt--;
            int flag=0;
            for(int i=0;i<4;i++){
                int x=v.second+dx[i];
                int y=v.first+dy[i];
                if(x<0||x>=W||y<0||y>=H)continue;
                if(G[y][x]=='#')continue;
                G[y][x]='#';
                que.push(make_pair(y,x));
                tmp++;
            }
            if(cnt==0){
                cnt=tmp;
                tmp=0;
                ans++;
            }
        }
        cout<<ans-1<<endl;
    
}
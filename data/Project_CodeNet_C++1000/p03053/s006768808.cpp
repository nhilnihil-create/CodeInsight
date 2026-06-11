#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;

int dr[4]={-1,0,0,1};
int dc[4]={0,-1,1,0};

void around(vector<vc> &field, int sr, int sc, queue<pair<int,int>> &que){
    field[sr][sc]='X';
    for(int i=0;i<4;i++){
        int nr=sr+dr[i];
        int nc=sc+dc[i];
        if(field[nr][nc]=='X'||field[nr][nc]=='#') continue;
        field[nr][nc]='#';
        que.push({nr,nc});
    }
}

int main(){
    int r,c;
    cin >> r >> c;
    vector<vc> field(r+2,vc(c+2,'#'));
    int cnt=0;
    queue<pair<int,int>> que2;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> field[i][j];
            if(field[i][j]=='#') que2.push({i,j});
        }
    } 
    int ans=0;
    queue<pair<int,int>> que;
    int count=0;
    while(1){
        count=0;
        while(!que2.empty()){
            auto x=que2.front();
            que2.pop();
            que.push(x);
            count++;
        }
        while(!que.empty()){
            auto x=que.front(); que.pop();
            //cout << x.first << " " << x.second << endl;
            around(field,x.first,x.second,que2);
            count++;
        }
        if(count==0) break;
        ans++;
    }

    cout << ans-1 << endl;
}
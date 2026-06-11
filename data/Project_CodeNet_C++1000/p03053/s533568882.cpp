#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#include<queue>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384


using namespace std;
using ll =long long;
using P = pair<int,int>;

#define MAX_H 1000
#define MAX_W 1000
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char filed[MAX_H][MAX_W];
bool check_filed[MAX_H][MAX_W];

int main(int argc, const char * argv[]) {
    int h, w;
    cin >> h >> w;
    
    queue<P> que;
    rep(y, h){
        string s;
        cin >> s;
        rep(x, w){
            filed[y][x] = s[x];
            check_filed[y][x] = false;
            if(s[x] == '#'){
                que.push(P(x, y));
                check_filed[y][x] = true;
            }
        }
    }

    int que_size = (int)que.size();
    int que_size_next = 0;
    int count = 0;
    int res = 0;
    while(que.size()){
        P p = que.front();
        que.pop();
        
        rep(i, 4){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(0<=nx&&nx<w&&0<=ny&&ny<h&&filed[ny][nx]=='.'&&check_filed[ny][nx]==false){
                check_filed[ny][nx] = true;
                que.push(P(nx, ny));
                que_size_next++;
            }
        }
        
        count++;
        if(count>=que_size){
            que_size = que_size_next;
            if(que_size_next>0) res++;
            count = 0;
            que_size_next = 0;
        }
    }
    
    cout << res << endl;
    return 0;
}

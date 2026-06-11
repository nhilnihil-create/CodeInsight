#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

struct grid{
    
    struct data{
        lli x,y,p;
    };
    
    vector<string> maze;
    
    grid(lli h,lli w){
        lli i;
        string s;
        maze.push_back(string(w+2,'#'));
        rep(i,0,h){
            cin>>s;
            maze.push_back('#'+s+'#');
        }
        maze.push_back(string(w+2,'#'));
    }
    
    void print(){
        lli i;
        rep(i,0,maze.size()){
            cout<<maze[i]<<endl;
        }
    }
    
    lli clear(lli h,lli w){
        lli i,j,point=0;
        data dat;
        queue<data> que;
        vector<string> check;
        check=maze;
        que.push({1,1,0});
        while(que.size()!=0){
            dat=que.front();
            if(dat.y==h&&dat.x==w){
                point=dat.p;
                break;
            }
            else{
                rep(i,-1,2){
                    rep(j,-1,2){
                        if(abs(i+j)==1){
                            if(check[dat.y+i][dat.x+j]=='.'){
                                que.push({dat.x+j,dat.y+i,dat.p+1});
                                check[dat.y+i][dat.x+j]='#';
//                                cout<<"・"<<dat.p+1<<"回目の移動で座標"<<dat.x+j<<","<<dat.y+i<<"に行ける"<<endl;
                            }
                        }
                    }
                }
                check[dat.y][dat.x]='#';
                que.pop();
            }
        }
        return point;
    }
    
    void count(lli h,lli w){
        lli i,j,cnt=0,ans;
        ans=clear(h,w);
//        cout<<"よってゴールには最短"<<ans<<"回でたどり着ける"<<endl;
        if(ans!=0){
            rep(i,1,h+1){
                rep(j,1,w+1){
                    if(maze[i][j]=='.'){
                        cnt++;
                    }
                }
            }
            cout<<cnt-1-ans<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    
};

int main() {
    lli h,w;
    lli i,j,k;
    cin>>h>>w;
    grid mazer(h,w);
//    mazer.print();
    mazer.count(h,w);
}

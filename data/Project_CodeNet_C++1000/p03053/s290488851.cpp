#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int h,w;

    cin >> h >> w;
    
    vector<vector<int>> a(h,vector<int>(w,0));
    queue<vector<int>> que;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char tmp;
            cin >> tmp;
            if(tmp=='.'){
                a[i][j]=-1;
            }else{
                que.push({i,j});
            }
        }
    }

    vector<int> x = {1,-1,0,0};
    vector<int> y = {0,0,1,-1};

    while(!que.empty()){
        auto now = que.front();
        que.pop();

        for(int k=0; k<4; k++){
            if(now[0]+x[k]<0 || now[0]+x[k]>h-1 || now[1]+y[k]<0 || now[1]+y[k]>w-1) continue;

            if(a[now[0]+x[k]][now[1]+y[k]]==-1){
                a[now[0]+x[k]][now[1]+y[k]]=a[now[0]][now[1]]+1;
                que.push({now[0]+x[k],now[1]+y[k]});
            }
        }
    }

    int num=-1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            num=max(num,a[i][j]);
        }
    }

    cout << num << endl;
    return 0;
}
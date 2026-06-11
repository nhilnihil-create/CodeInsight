#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <math.h>
#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
#define NIL -1

vector<vector<int>> s(100, vector<int>(100));
vector<vector<int>> d(100, vector<int>(100, NIL));

int bfs(int y, int x, int h, int w){
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    pair<int, int> u;
    while(!q.empty()){
        u = q.front();
        int old_y = u.first;
        int old_x = u.second;
        q.pop();
        int new_y;
        int new_x;
        for(int i=-1; i<=1; i=i+2){
            new_x=old_x+i;
            new_y=old_y;
            if(new_x>=0 && new_x<w){
                if(d[new_y][new_x]==NIL && s[new_y][new_x]!=1){
                    d[new_y][new_x]=d[old_y][old_x]+1;
                    q.push(make_pair(new_y, new_x));
                    //cout << new_y << " " << new_x << " " << old_y << " " << old_x << endl;
                }
            }
        }
        for(int i=-1; i<=1; i=i+2){
            new_x=old_x;
            new_y=old_y+i;
            if(new_y>=0 && new_y<h){
                if(d[new_y][new_x]==NIL && s[new_y][new_x]!=1){
                    d[new_y][new_x]=d[old_y][old_x]+1;
                    q.push(make_pair(new_y, new_x));
                    //cout << new_y << " " << new_x << " " << old_y << " " << old_x << endl;
                }
            }
        }
    }
}

int main() {
    int h;
    int w;
    string tmp_s;
    cin >> h >> w;

    int num_blk=0;
    for(int i=0; i<h; i++){
        cin >> tmp_s;
        for(int j=0; j<w; j++){
            if(tmp_s[j]=='.'){
                s[i][j]=0;
            }else{
                s[i][j]=1;
                num_blk++;
            }
        }
    }

    if(s[0][0]==1 || s[h-1][w-1]==1){
        cout << -1 << endl;
    }else{
        d[0][0]=1;
        bfs(0, 0, h, w);
        if(d[h-1][w-1]!=NIL){
            LL ans=h*w-num_blk-d[h-1][w-1];
            cout << ans << endl;
            //cout << h*w << " " << num_blk << " " << d[h-1][w-1] << endl;
        }else{
            cout << -1 << endl;
        }
    }

    //for(int i=0; i<h; i++){
    //    for(int j=0; j<w; j++){
    //        cout << d[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    return 0;
}

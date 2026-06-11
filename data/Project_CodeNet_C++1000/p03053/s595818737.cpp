#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

struct COODINATE
{
public:
    int x, y, n;
};

vector<string> Gin;
Graph Gout;
queue<COODINATE> Q;

int search(int x, int y, int n, int h, int w){
    if(x<0 || w<=x || y<0 || h<=y || Gout[y][x] != -1){
        return 0;
    }
    if(Gin[y][x] == '#'){
        Gout[y][x] = 0;
        Q.push(COODINATE{x+1, y, n});
        Q.push(COODINATE{x-1, y, n});
        Q.push(COODINATE{x, y+1, n});
        Q.push(COODINATE{x, y-1, n});
        return 0;
    }
    Gout[y][x] = n+1;
    Q.push(COODINATE{x+1, y, n+1});
    Q.push(COODINATE{x-1, y, n+1});
    Q.push(COODINATE{x, y+1, n+1});
    Q.push(COODINATE{x, y-1, n+1});
    return n+1;
}

int main(){
    int h, w;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        Gin.push_back(s);
    }
    Gout.assign(h, vector<int>(w, -1));
    int ans = 0;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(Gin[i][j] == '#'){
                Q.push(COODINATE{j, i, 0});
            }
        }
    }
    
    while(!Q.empty()){
        COODINATE coodinate = Q.front();
        Q.pop();
        int num = search(coodinate.x, coodinate.y, coodinate.n, h, w);
        if(ans < num){
            ans = num;
        }
    }

    cout << ans << endl;
    return 0;
}
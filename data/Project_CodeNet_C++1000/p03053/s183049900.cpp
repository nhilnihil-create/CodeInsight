#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> map;
typedef struct 
{
    int x;
    int y;
}P;
queue<P> que;
int step[1000][1000];

bool CheclBoard(int H, int W)
{
    bool ret = true;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(map[i][j]!='#')
            {
                ret = false;
                break;
            }
        }
    }
    return ret;
}


int main(void)
{
    vector<P>move = {{0,1},{0,-1},{1,0},{-1,0}};
    int H, W;
    cin >> H >> W;
    map.resize(H);
    for(int i=0;i<H;i++) cin >> map[i];

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(map[i][j]=='#')
            {
                que.push(P{i,j});            
                step[i][j]=0;
            }
        }
    }

    int maxNum = 0;    
    while(!que.empty())
    {
        P pos = que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int nX = pos.x + move[i].x;
            int nY = pos.y + move[i].y;

            if((nX>=0)&&(nX<H)&&(nY>=0)&&(nY<W)&&(map[nX][nY]!='#'))
            {
                map[nX][nY]='#';
                que.push(P{nX,nY});
                step[nX][nY]=step[pos.x][pos.y] + 1;
                if(maxNum < step[nX][nY]) maxNum = step[nX][nY];
            }
        }
    }
        
    cout << maxNum << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int counting(int N_H, int N_W, vector< vector<int> > &Graph, queue< pair<int, int> > &PaintingPos)
{
    /*
    PaintingPosは黒色の座標, Graph[y][x] = 1
    */
    int count = 0;
    pair<int, int> pos_y_x;
    queue< pair<int, int> > PaintingPos_new;
    int x, y;
    pair<int, int> dy_dx[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1) };
    while( PaintingPos.size() >0 || PaintingPos_new.size()>0 )
    {
        // cout << "SIZE* " << PaintingPos.size() << "  " << PaintingPos_new.size() << endl;
        while( PaintingPos.size()>0 )
        {
            pos_y_x = PaintingPos.front(); PaintingPos.pop();
            for(int i=0; i<4; i++)
            {
                y = pos_y_x.first + dy_dx[i].first, x = pos_y_x.second + dy_dx[i].second;
                if(x <0 || x>= N_W || y<0 || y>= N_H || Graph[y][x] == 1) continue;
                Graph[y][x] = 1;
                PaintingPos_new.push(make_pair(y, x) );
            }
        }
        count++;
        swap( PaintingPos, PaintingPos_new );
    }

    return count-1; // 1回分多く数えている
}



int main(void)
{
    /*
    ARC 037 B バウムテスト
    https://atcoder.jp/contests/arc037/tasks/arc037_b
    */
    int N_H, N_W;
    cin >> N_H >> N_W;

    vector< vector<int> > Graph(N_H, vector<int>(N_W) );
    queue< pair<int, int> > PaintingPos; // height, width

    char color; // black -> #, 1. white->., 0で
    for(int i=0; i<N_H; i++)
    {
        for(int j=0; j<N_W; j++)
        {
            cin >> color;
            if(color == '#')
            {
                Graph[i][j] = 1;
                PaintingPos.push(make_pair(i, j) );
            }
        }
    }

    if(PaintingPos.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << counting(N_H, N_W, Graph, PaintingPos) << endl;
    }


    return 0;
}

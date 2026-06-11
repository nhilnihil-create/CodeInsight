# include <iostream>
# include <queue>
# include <climits>
using namespace std;
 
int H;
int W;
char A[1005][1005];
int counter=0;
int shortestpath[1005][1005];
bool visited[1005][1005];
int maximum=INT_MIN;
int dr[4]={1, -1, 0, 0};
int dc[4]={0, 0, -1, 1};
queue< pair<int, int> > starting;

bool inside (int row, int column)
{
    if (row<0 || row>H || column<0 || column>W)
    {
        return false;
    }

    return true;
}

void bfs (queue< pair<int, int> > starting)
{
    queue< pair<int, int> > q;

    while (!starting.empty())
    {
        q.push(make_pair(starting.front().first, starting.front().second));
        visited[starting.front().first][starting.front().second]=true;
        starting.pop();
    }

    while (!q.empty())
    {
        pair<int, int> u=q.front();
        q.pop();

        for (int i=0; i<4; i++)
        {
            int nextrow=u.first+dr[i];
            int nextcolumn=u.second+dc[i];

            if (inside(nextrow, nextcolumn) && !visited[nextrow][nextcolumn])
            {
                shortestpath[nextrow][nextcolumn]=shortestpath[u.first][u.second]+1;
                q.push(make_pair(nextrow, nextcolumn));
                visited[nextrow][nextcolumn]=true;
            }
        }

    }
}

int main()
{
    cin>>H>>W;

    for (int i=1; i<=H; i++)
    {
        for (int j=1; j<=W; j++)
        {
            cin>>A[i][j];

            if (A[i][j]=='#')
            {
                starting.push(make_pair(i, j));
            }
        }
    }

    bfs(starting);

    for (int i=1; i<=H; i++)
    {
        for (int j=1; j<=W; j++)
        {
            if (shortestpath[i][j]>maximum)
            {
                maximum=shortestpath[i][j];
            }
        }
    }

    cout<<maximum<<endl;
}
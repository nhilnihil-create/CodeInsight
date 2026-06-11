#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int main()
{
    int h,w; cin >> h >> w;
    vector<string> a;

    for( int i = 0; i < h; ++i )
    {
        string s; cin >> s;
        a.push_back(s);
    }
    vector< vector<int> > color(h,vector<int>(w,-1));
    vector< vector<int> > dist(h,vector<int>(w,0));
    int z = 0;
    for( int i = 0; i < h; ++i )
    {
        for( int j = 0; j < w; ++j )
        {
            if( a[i][j] == '#' )
            {
                color[i][j] = 1;
                z++;
            }
        }
    }

    int count = 0;
    int cnt = 0;
    queue< pair<int,int> > q;
    for( int i = 0; i < h; ++i )
    {
        for( int j = 0; j < w; ++j )
        {
            if( a[i][j] == '#' )
            {
                q.push(make_pair(i,j));
                cnt++;
            }
        }
    }
    
    while( !q.empty() )
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for( int i = 0; i < 4; ++i )
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( nx < 0 || ny < 0 || nx >= h || ny >= w )
            {
                continue;
            }
            else if( color[nx][ny] != -1 )
            {
                continue;
            }
            color[nx][ny] = 1;
            q.push(make_pair(nx,ny));
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    
    int max = -100;
    for( int i = 0; i < h; ++i )
    {
        for( int j = 0; j < w; ++j )
        {
            if( max < dist[i][j] )
            {
                max = dist[i][j];
            }
        }
    }
    cout << max << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

struct idou
{
    int y;
    int x;
    int ny;
    int nx;
};
vector<vector<int> > coin;
int main()
{
    int h,w; cin >> h >> w;
    coin.resize(h);
    rep(i,h)coin[i].resize(w);
    rep(i,h)
    {
        rep(j,w)
        {
            cin >> coin[i][j];
        }
    }
    vector<idou> sousa;
    int flag = 0;
    rep(i,h-1)
    {
        rep(j,w)
        {
            if(coin[i][j]%2==1)
            {
                coin[i+1][j]++;
                idou temp;
                temp.y = i;temp.x = j;temp.ny = i+1;temp.nx = j;
                sousa.push_back(temp);
            }

        }
    }
    rep(i,w-1)
    {
        if(coin[h-1][i]%2==1)
        {
            coin[h-1][i+1]++;
            idou temp;
            temp.y = h-1;temp.x = i;temp.ny = h-1;temp.nx = i+1;
            sousa.push_back(temp);
        }
    }

    int num = (int)sz(sousa);
    cout << num << endl;
    rep(i,num)
    {
        ++sousa[i].y;
        ++sousa[i].x;
        ++sousa[i].ny;
        ++sousa[i].nx;
        cout << sousa[i].y << " " << sousa[i].x << " " << sousa[i].ny << " " << sousa[i].nx << endl;
    }

}
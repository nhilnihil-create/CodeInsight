#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(),v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 2000000000;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

typedef tuple<string, int, int> TUP;

bool tuplesort(const TUP &right, const TUP &left)
{
    if (get<0>(right) != get<0>(left))
    {
        return get<0>(left) < get<0>(right);
    }
    if (get<1>(left) != get<1>(right))
    {
        return get<1>(left) > get<1>(right);
    }
    return get<2>(left) < get<2>(right);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> A(H,vector<char> (W));
    vector<vector<int>> dist(H, vector<int>(W, -1));
    int ans = 0;
    queue<int> que;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W;j++)
        {
            cin >> A[i][j];
            if(A[i][j] =='#'){
                que.push(i);
                que.push(j);
                dist[i][j] = 0;
            }
        }
    }

    while(!que.empty())
    {
        int h = que.front();
        que.pop();
        int w = que.front();
        que.pop();
        if(dist[h][w] != -1)
        {
            for (int dir = 0; dir < 4;dir++)
            {
                int nh = h + dy[dir];
                int nw = w + dx[dir];
                if(nh < H && nw < W && nh >= 0 && nw >= 0){
                    if(dist[nh][nw] == -1 && A[nh][nw] == '.'){
                        que.push(nh);
                        que.push(nw);
                        dist[nh][nw] = dist[h][w] + 1;
                        A[nh][nw] = '#';
                    }
                }
            }
        }
    }

    for (int i = 0; i < H;i++)
    {
        for (int j = 0; j < W;j++)
        {
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << endl;
}
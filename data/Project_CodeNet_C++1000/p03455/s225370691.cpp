#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;


int lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

vector<string> field;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, W;
bool seen[510][510];

void dfs(int h, int w)
{
    seen[h][w] = true;
    for (int dir = 0; dir < 4;dir++)
    {
            int nh = h + dx[dir];
            int nw = w + dy[dir];
        
        if(nh < 0|| nh >= H || nw < 0 || nw >= W){
            continue;
        }
        if(field[nh][nw] == '#'){
            continue;
        }
        if(seen[nh][nw]){
            continue;
        }
        dfs(nh, nw);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int a, b;
    cin >> a >> b;
    if(a*b % 2 == 0){
        cout << "Even" << endl;
    }
    else{
        cout << "Odd" << endl;
    }
}
#include <iostream>
#include <cstdio>
#include <vector>
#define N 8000
using namespace std;

int x, y, cnt, z;
int d[4005][16005];
int e[4005][N * 2];
string s;
vector<int> v[2];

bool f(int p) {
    int i;
    d[0][v[0][0]+N] = 1;
    for(i = 1; i < v[0].size(); i++)
    {
        int t = v[0][i];
        for(int j = 0; j <= 2 * N; j++)
        {
            if(j >= t && d[i-1][j-t]) d[i][j] = 1;
            if(j + t <= 2 * N && d[i-1][j+t]) d[i][j] = 1;
        }
    }
    return d[i-1][p + N];
}

bool g(int p) {
    int i;
    e[0][v[1][0] + N] = 1;
    for(int i = 1; i < v[1].size(); i++)
    {
        int k = v[1][i];
        for(int j = 0; j <= 2 * N; j++)
        {
            if(j >= k && e[i - 1][j - k]) e[i][j] = 1;
            if(j + k <= 2 * N && e[i - 1][j + k]) e[i][j] = 1;
        }
    }
    return e[v[1].size() - 1][p + N];
}

int main()
{
    int i;
    cin>>s>>x>>y;
    s += 'T';
    v[1].push_back(0);
    for(int i = 0; s[i]; i++) {
        if(s[i]=='F') cnt++;
        else {
            v[z].push_back(cnt);
            z = !z;
            cnt = 0;
        }
    }
    if(f(x) & g(y)) cout<<"Yes";
    else cout<<"No";
    return 0;
}

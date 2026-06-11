#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define N 8000
using namespace std;

int x, y, cnt, z;
bitset<N * 2> bs;
int d[4005][16005];
int e[4005][N * 2];
string s;
vector<int> v[2];

bool f(int p) {
    int i;
    bs = 0;
    bs[N + v[0][0]] = true;
    for(i = 1; i < v[0].size(); i++)
    {
        bs = (bs << v[0][i]) | (bs >> v[0][i]);
//        int t = v[0][i];
//        for(int j = 0; j <= 2 * N; j++)
//        {
//            if(j >= t && d[i-1][j-t]) d[i][j] = 1;
//            if(j + t <= 2 * N && d[i-1][j+t]) d[i][j] = 1;
//        }
    }
    return bs[N + p];
}

bool g(int p) {
    bs = 0;
    int i;
    bs[v[1][0] + N] = true;
//    e[0][v[1][0] + N] = 1;
    for(int i = 1; i < v[1].size(); i++)
    {
        bs = (bs << v[1][i]) | (bs >> v[1][i]);
//        int k = v[1][i];
//        for(int j = 0; j <= 2 * N; j++)
//        {
//            if(j >= k && e[i - 1][j - k]) e[i][j] = 1;
//            if(j + k <= 2 * N && e[i - 1][j + k]) e[i][j] = 1;
//        }
    }
    return bs[p + N];
//    return e[v[1].size() - 1][p + N];
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

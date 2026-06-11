#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(),(x).end())
#define Sort2(x) sort((x).begin(),(x).end(), greater<int>())
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main()
{
    int h,w; cin >> h >> w;
    string field[h];
    rep(i,h) cin >> field[i];
    
    int dx[] = {-1,0,1,-1,1,-1,0,1};
    int dy[] = {1,1,1,0,0,-1,-1,-1};

    rep(hi,h) rep(wi,w){
        if(field[hi][wi]=='.') field[hi][wi] = '0';
        if(field[hi][wi] != '#') continue;
        rep(k,8){
            int nx = wi + dx[k]; int ny = hi + dy[k];
            if(nx < 0 || ny < 0 || nx >= w || ny >= h || field[ny][nx]=='#') continue;
            if(field[ny][nx]=='.') field[ny][nx] = '0';
            field[ny][nx]++;
        }
    }
    rep(hi,h){
        cout << field[hi] << endl;
    }
}

/*
g++ c.cpp
./a.out

oj d https://atcoder.jp/contests/abc172/tasks/abc172_c
g++ c.cpp
oj t
*/

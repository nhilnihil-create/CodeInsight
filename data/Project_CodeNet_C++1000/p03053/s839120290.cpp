#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;
typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int H,W;
int dh[]={1,0,-1,0};
int dw[]={0,1,0,-1};


int main(){
    cin >>H>>W;
    int ans=0;

    vector<string> grid(H);
    rep(i,H) cin >> grid[i];

    queue<P> q;
    queue<P> r;

    rep(i,H){
        rep(j,W){
            if(grid[i][j] == '#')   q.push(make_pair(i,j));
        }
    }

    while(!q.empty()||!r.empty()){
        while(!q.empty()){

            int  h =q.front().first;
            int  w =q.front().second;
            q.pop();

            rep(dir,4){
                int nh = h+dh[dir];
                int nw = w+dw[dir];

                if(nh<0||nw<0||nh==H||nw==W) continue;
                if(grid[nh][nw]=='#') continue;

                grid[nh][nw] = '#';
                r.push(make_pair(nh,nw));
            }
        }
        ans++;
        swap(q,r);
        queue<P>().swap(r);
    }
    cout << ans-1<<endl;
}
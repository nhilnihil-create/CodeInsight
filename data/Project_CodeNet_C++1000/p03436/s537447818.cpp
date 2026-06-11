#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const int INF=99999999;
char s[55][55];
int d[55][55];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
queue<pair<int,int> > q;


int main(){
    int h,w,num=0;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s[i][j];
            if(s[i][j]=='.') num++;
            d[i][j]=INF;
        }
    }
    q.push(make_pair(0,0));
    d[0][0]=0;
    while(q.size()){
        pair<int,int> p=q.front(); q.pop();
        if(p.first==w-1 && p.second==h-1){
            break;
        }
        for(int i=0;i<4;i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
            if(nx>=0 && nx<w && ny>=0 && ny<h && d[ny][nx]==INF && s[ny][nx]=='.'){
                q.push(make_pair(nx,ny));
                d[ny][nx]=d[p.second][p.first]+1;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            //cout<<d[i][j]<<" ";
        }
        //cout<<endl<<endl;
    }

    if(d[h-1][w-1]==INF){
        cout<<-1<<endl;
    }else{
        cout<<num-d[h-1][w-1]-1<<endl;
    }
}
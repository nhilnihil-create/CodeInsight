#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <queue>
#include <map>
#include <ctime>

using namespace std;

#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()

int co[100005];
vector<vector<int>> to(100005),ot(100005);
int parent[100005];
int point[100005];

int main(){
    int n,m;
    cin >> n >> m;
    rip(i,n,0){
        co[i]=0;
        parent[i]=-1;
        point[i]=0;
    }
    rip(i,n+m-1,0){
        int a,b;
        cin >> a >> b;
        to[a-1].push_back(b-1);
        ot[b-1].push_back(a-1);
        co[a-1]++;
    }
    queue<int> q;
    rip(i,n,0){
        if(co[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int no=q.front();
        q.pop();
        rip(i,ot[no].size(),0){
            int y=ot[no][i];
            co[y]--;
            if(co[y]==0){
                q.push(y);
                point[y]=point[no]+1;
            }
        }
    }
    rip(i,n,0){
        int mi=INT_MAX;
        rip(j,ot[i].size(),0){
            if(mi>point[ot[i][j]]){
                mi=point[ot[i][j]];
                parent[i]=ot[i][j];
            }
        }
    }
    rip(i,n,0){
        printf("%d\n",parent[i]+1);
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>Graph(n);
    vector<pair<int,int>>index;
    vector<bool>visited(n);
    queue<int>que;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        index.push_back(make_pair(a,b));
    }
    int answer = 0;
    REP(i,m){
        REP(j,n)
            Graph[j].clear();
        REP(j,n)visited[j]=false;
        REP(j,m){
            if(i==j)continue;
            Graph[index[j].first].push_back(index[j].second);
            Graph[index[j].second].push_back(index[j].first);
        }
        que.push(0);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            visited[now]=true;
            REP(j,Graph[now].size()){
                if(!visited[Graph[now][j]])que.push(Graph[now][j]);
            }
        }
        REP(j,n){
            if(visited[j]==false){
                answer++;
                break;
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}
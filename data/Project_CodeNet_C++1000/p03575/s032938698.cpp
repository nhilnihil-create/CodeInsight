#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
#define NIL -1

int n;
int m;
vector<vector<int>> ab(100, vector<int>(100));
vector<int> is_visit(100, NIL);

void bfs(int s){
    queue<int> q;
    q.push(s);
    int u;
    while(!q.empty()){
        u=q.front();
        is_visit[u]=1;
        q.pop();
        for(int v=0; v<n; v++){
            if(ab[u][v]==1 && is_visit[v]==NIL){
                q.push(v);
            }
        }
    }
}

int main(){
    vector<int> a;
    vector<int> b;
    int tmp_a;
    int tmp_b;
    int ans=0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> tmp_a >> tmp_b;
        tmp_a--;
        tmp_b--;
        a.push_back(tmp_a);
        b.push_back(tmp_b);
        ab[tmp_a][tmp_b]=1;
        ab[tmp_b][tmp_a]=1;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            is_visit[j]=NIL;
        }
        ab[a[i]][b[i]]=0;
        ab[b[i]][a[i]]=0;
        bfs(0);
        bool ok=true;
        for(int k=0; k<n; k++){
            if(is_visit[k]==NIL){
                ok=false;
                break;
            }
        }
        if(ok==false){
            ans++;
        }
        ab[a[i]][b[i]]=1;
        ab[b[i]][a[i]]=1;        
    }

    cout << ans << endl;

    return 0;
}

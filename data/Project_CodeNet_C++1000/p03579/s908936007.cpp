#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "No" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N,M;
    int A[114514],B[114514];
    int color[114514]={};
    bool visited[114514]={};
    cin >> N >> M;
    REP(i,M){
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
    }
    vector<int> G[114514];
    REP(i,M){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    queue<int> P;
    P.push(0);
    color[0]=1;
    
    bool able=true;
    while(!P.empty()){
        int p=P.front();
        P.pop();
        visited[p]=true;
        for(int i=0;i<G[p].size();i++){
            if(visited[G[p][i]]==true){
                if(color[G[p][i]]==color[p]){
                    able=false;
                }
            }else{
                P.push(G[p][i]);
                color[G[p][i]]=3-color[p];
            }
        }
        
    }
    //cout << able << endl;
    //REP(i,N){cout << color[i] << " ";}cout << endl;
    if(able){
        int C=0,D=0;
        REP(i,N){
            if(color[i]==1){
                C++;
            }else if(color[i]==2){
                D++;
            }
        }
        cout << C*D-M << endl;
    }else{
        cout << N*(N-1)/2 - M << endl;
    }
    return 0;
}


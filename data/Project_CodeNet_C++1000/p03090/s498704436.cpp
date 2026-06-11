#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<vector<int>> edge(N,vector<int>());
    if(N%2==0){
        // すべての頂点間に辺を張ると　N*(N-1)/2
        // 頂点番号が足してN+1になるペア間の辺を除く
        cout << N*(N-1)/2 - N/2 << endl;
        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                if(i+j==(N+1)) continue;
                edge[i].push_back(j);
            }
        }
    }else{
        // 偶数の時と同じことをNを除いて行う
        // 最後にすべての頂点に対してNから辺を張ればOK
        cout << (N-1)*(N-2)/2 - (N-1)/2 + N-1 << endl;
        for(int i=1;i<=N-1;i++){
            for(int j=i+1;j<=N-1;j++){
                if(i+j==(N)) continue;
                edge[i].push_back(j);
            }
            edge[i].push_back(N);
        }
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<edge[i].size();j++){
            cout << i << " " << edge[i][j] << endl;
        }
    }
    return 0;
}
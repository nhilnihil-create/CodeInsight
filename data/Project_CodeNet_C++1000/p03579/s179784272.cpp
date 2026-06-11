#include <bits/stdc++.h>
#include <numeric>

using namespace std;
#define all(x) (x).begin(),(x).end()

using gragh = vector<vector<int>>;
vector<int> color;

bool dfs(const gragh &edge_gragh,int v,int cur=0){
    color[v] = cur;
    for(auto next_v:edge_gragh[v]){
        if (color[next_v]!=-1){
            if(color[next_v]==cur) {
                return false;
            }
            continue;
        }
        if(!dfs(edge_gragh,next_v,1-cur)) return false;
    }
    return true;
}


int main() {

    int N;
    int M;
    cin>>N>>M;

    gragh edge_gragh(N);
    for (int i = 0; i < M; ++i) {
        int A,B;
        cin>>A>>B;
        A--;
        B--;
        edge_gragh[A].push_back(B);
        edge_gragh[B].push_back(A);
    }

    color.assign(N,-1);
    bool is_bipartite = true;
    for(int v=0;v<N;++v){
        if(color[v]!= -1) continue;
        if(!dfs(edge_gragh,v)){
            is_bipartite = false;
        }
    }

    if (is_bipartite){
        long long sum = accumulate(all(color),0LL);
        long long ans =sum * ((long long)N-sum) - (long long)M;
        cout<<ans<<endl;
    }else{
        long long ans =(((long long)N * ((long long)N - 1)) / 2) - (long long)M;
        cout << ans << endl;
    }
}
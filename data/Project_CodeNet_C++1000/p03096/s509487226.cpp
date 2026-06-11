#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

vector<int> g[200010];
int ind[200010]={};
ll dp[200010]={};

int main(){
    int N; cin >> N;
    int c[N];
    for(int i=0;i<N;i++){
        cin >> c[i];
    }
    
    for(int i=N-1;i>=0;i--){
        g[c[i]].push_back(i);
    }
    
    dp[0]=1;
    for(int i=0;i<N;i++){
        dp[i+1]+=dp[i];
        dp[i+1]%=MOD;
        int j=g[c[i]].back();
        g[c[i]].pop_back();
        if(g[c[i]].empty()) continue;
        int k=g[c[i]].back();
        //cout << j << " " << k << endl;
        if(k==(j+1)) continue;
        dp[k]+=dp[j];
        dp[k]%=MOD;
    }
    cout << dp[N-1]%MOD << endl;
}
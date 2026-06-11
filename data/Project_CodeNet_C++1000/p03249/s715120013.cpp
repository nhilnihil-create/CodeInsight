#include<bits/stdc++.h>
using namespace std;
long long h[100009];
long long sz[100009];
long long f[100009];
long long D[100009];
vector<long long> v[100009];
map<long long,long long> M;
void dfs(long long x, long long de){
    f[x] = 1;
    h[x] = de;
    for(long long i = 0; i < v[x].size(); i++){
        if(!f[v[x][i]]) dfs(v[x][i], de + 1);
    }
}
main(){
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> D[i];
        M[D[i]] = i;
        sz[i] = 1;
    }
    long long t = D[1];
    sort(D + 1, D + n + 1);
    for(long long i= n; i >= 2; i--){
        long long k = M[D[i]];
        long long diff = n - 2 * sz[k];
        if(diff <= 0 || !M[D[i] - diff]){
            cout << -1 << endl;
            return 0;
        }
 
        v[k].push_back(M[D[i]-diff]);
        v[M[D[i] - diff]].push_back(k);
        sz[M[D[i] - diff]] += sz[k];
 
    }
 
    dfs(1,0);
    long long S = 0;
    for(long long i = 1; i <= n; i++){
        S += h[i];
    }
    if(S == t){
        for(long long i = 1; i <= n; i++){
            for(long long j = 0; j < v[i].size(); j++){
                if(i < v[i][j]){
                    cout<<i<<" "<<v[i][j]<<endl;
                }
            }
        }
    }
    else{
        cout<< -1 << endl;
        return 0;
    }
}
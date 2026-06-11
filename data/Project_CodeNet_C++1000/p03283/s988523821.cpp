#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;
struct Edge { int from, to; long long cost; };
using Graph = vector<vector<Edge>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m,q;
    cin>>n>>m>>q;
    ll c_sum[n+1][n+1]={};
    for(int i=0,l,r;i<m;i++){
        cin>>l>>r;
        c_sum[l][r]++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c_sum[i+1][j+1]+=c_sum[i+1][j]+c_sum[i][j+1]-c_sum[i][j];
        }
    }
    for(int i=0,a,b;i<q;i++){
        cin>>a>>b;
        cout<<c_sum[b][b]-c_sum[b][a-1]-c_sum[a-1][b]+c_sum[a-1][a-1]<<endl;
    }
}
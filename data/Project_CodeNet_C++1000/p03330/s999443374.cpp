#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n,c;cin >> n >> c;
    vector<vector<int>> d(c,vector<int>(c));
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            cin >> d[i][j];
        }
    }
    vector<vector<int>> color(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> color[i][j];
            color[i][j]--;
        }
    }
    vector<vector<int>> sum(3,vector<int>(c));
    for(int C=0;C<c;C++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j)%3==0){
                    sum[0][C]+=d[color[i][j]][C];
                }
                else if((i+j)%3==1){
                    sum[1][C]+=d[color[i][j]][C];
                }
                else sum[2][C]+=d[color[i][j]][C];
            }
        }
    }
    int ans=INF;
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<c;k++){
                if(i==j||j==k||i==k) continue;
                ans=min(ans,sum[0][i]+sum[1][j]+sum[2][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
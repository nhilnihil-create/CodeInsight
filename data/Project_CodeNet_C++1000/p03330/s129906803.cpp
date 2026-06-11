#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,c;cin >> n >> c;
    int a[c][c];
    int b[n][n];
    int ans=inf;
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> t(3,vector<int>(c));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> b[i][j];
            b[i][j]--;
            t[(i+j)%3][b[i][j]]++;
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<c;k++){
                if(i==j||j==k||k==i){
                    continue;
                }
                int res=0;
                int p[3]={i,j,k};
                for(int l=0;l<3;l++){
                    for(int m=0;m<c;m++){
                        res+=a[m][p[l]]*t[l][m];
                    }
                }
                chmin(ans,res);
            }
        }
    }
    cout << ans << endl;
}